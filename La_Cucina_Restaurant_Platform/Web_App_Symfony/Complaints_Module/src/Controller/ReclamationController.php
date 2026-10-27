<?php

namespace App\Controller;

use App\Entity\Reclamation;
use App\Entity\Reponse;
use App\Entity\WhatsappNotif;
use App\Form\ReclamationType;
use App\Form\ReponseType;
use App\Form\SearchFormType;
use App\Repository\ReclamationRepository;
use App\Repository\ReponseRepository;
use Doctrine\ORM\EntityManagerInterface;
use Dompdf\Dompdf;
use Knp\Component\Pager\PaginatorInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Mailer\MailerInterface;
use Symfony\Component\Notifier\Notification\Notification;
use Symfony\Component\Notifier\NotifierInterface;
use Symfony\Component\Routing\Annotation\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\ParamConverter;
use Dompdf\Options;
use Twilio\Rest\Client;
use Symfony\Component\Mime\Email;
#[Route('/reclamation')]
class ReclamationController extends AbstractController
{


    #[Route('/', name: 'app_reclamation_index', methods: ['GET'])]
    public function index(ReclamationRepository $reclamationRepository,Request $request,PaginatorInterface $paginator): Response
    {

        $pagination = $paginator->paginate(
            $reclamationRepository->findAll(), // Query
            $request->query->getInt('page', 1), // Page number
            10 // Limit per page
        );

        return $this->render('reclamation/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }
    #[Route('/back', name: 'app_reclamation_index2', methods: ['GET'])]
    public function index2(Request $request, ReclamationRepository $reclamationRepository,  PaginatorInterface $paginator): Response
    {
        $pagination = $paginator->paginate(
            $reclamationRepository->findAll(), // Query
            $request->query->getInt('page', 1), // Page number
            10 // Limit per page
        );

        return $this->render('reclamation/indexBack.html.twig', [
            'reclamations' => $pagination,
        ]);}
    #[Route('/new', name: 'app_reclamation_new', methods: ['GET', 'POST'])]
    public function new(Request $request, EntityManagerInterface $entityManager, MailerInterface $mailer): Response
    {
        $sid = "YOUR_TWILIO_ACCOUNT_SID";
        $token = "YOUR_TWILIO_AUTH_TOKEN";
        $twilio = new Client($sid, $token);

        $reclamation = new Reclamation();
        $form = $this->createForm(ReclamationType::class, $reclamation);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            try {
                // Sending WhatsApp message
                $message = $twilio->messages->create(
                    "whatsapp:+21692625106",
                    [
                        "from" => "whatsapp:+14155238886",
                        "body" => "A new Reclamation has been submitted."
                    ]
                );

                // Saving WhatsApp notification
                $whatsappNotif = new WhatsappNotif();
                $whatsappNotif->setText("A new reclamation has been added.");
                $whatsappNotif->setReclamation($reclamation);
                $entityManager->persist($whatsappNotif);
                $email = (new Email())
                    ->from('kassouma216@gmail.com')
                    ->to('kassembh425@gmail.com')
                    ->subject('New Reclamation Submitted')
                    ->html('<p>A new reclamation has been submitted.</p>');

                $mailer->send($email);
                // Persisting the reclamation
                $entityManager->persist($reclamation);
                $entityManager->flush();

                // Redirecting to index page
                return $this->redirectToRoute('app_reclamation_index');
            } catch (\Exception $e) {
                // Handle exception
                $this->addFlash('error', "Failed to send WhatsApp message: " . $e->getMessage());
            }

        }

        return $this->render('reclamation/new.html.twig', [
            'reclamation' => $reclamation,
            'form' => $form->createView(),
        ]);
    }






    ///////////////////////////
    #[Route('/validate-email', name: 'validate_email')]
    public function validateEmail(Request $request, MailerInterface $mailer): Response
    {


        $message = (new Email())
            ->from('kassembh425@gmail.com')
            ->to('kassembh425@gmail.com')
            ->subject('Hello')
            ->text('Bonjour12');

        $mailer->send($message);

        return new Response('Message sent.');


        dump('code23');
    }
    /// ///////////








    #[Route('/{id}', name: 'app_reclamation_show', methods: ['GET'])]
    public function show(Reclamation $reclamation): Response
    {
        return $this->render('reclamation/show.html.twig', [
            'reclamation' => $reclamation,
        ]);
    }
    #[Route('/{id}/back', name: 'app_reclamation_show2', methods: ['GET'])]
    #[ParamConverter('reclamation', class: 'App\Entity\Reclamation')]
    public function show2(Reclamation $reclamation): Response
    {
        return $this->render('reclamation/showForAdmin.html.twig', [
            'reclamation' => $reclamation,
        ]);
    }
    /*  #[Route('/{id}/edit', name: 'app_reclamation_edit', methods: ['GET', 'POST'])]
      public function edit(Request $request, Reclamation $reclamation, EntityManagerInterface $entityManager): Response
      {
          $form = $this->createForm(ReclamationType::class, $reclamation);
          $form->handleRequest($request);

          if ($form->isSubmitted() && $form->isValid()) {
              $entityManager->flush();

              return $this->redirectToRoute('app_reclamation_index', [], Response::HTTP_SEE_OTHER);
          }

          return $this->renderForm('reclamation/edit.html.twig', [
              'reclamation' => $reclamation,
              'form' => $form,
          ]);
      }*/
    #[Route('/{id}/edit', name: 'app_reclamation_edit', methods: ['GET', 'POST'])]
    public function edit(Request $request, Reclamation $reclamation, EntityManagerInterface $entityManager, NotifierInterface $notifier): Response
    {
        $form = $this->createForm(ReclamationType::class, $reclamation);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();

            // Send a notification
            $notification = new Notification('Reclamation Edited', ['browser']);
            $notifier->send($notification);

            return $this->redirectToRoute('app_reclamation_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->renderForm('reclamation/edit.html.twig', [
            'reclamation' => $reclamation,
            'form' => $form,
        ]);
    }

    #[Route('/{id}/delete', name: 'app_reclamation_delete', methods: ['POST'])]
    public function delete(Request $request, Reclamation $reclamation, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete'.$reclamation->getId(), $request->request->get('_token'))) {
            $entityManager->remove($reclamation);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_reclamation_index', [], Response::HTTP_SEE_OTHER);
    }
    #[Route('/{id}', name: 'app_reclamation_delete2', methods: ['POST'])]
    public function delete2(Request $request, Reclamation $reclamation, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete'.$reclamation->getId(), $request->request->get('_token'))) {
            $entityManager->remove($reclamation);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_reclamation_index2', [], Response::HTTP_SEE_OTHER);
    }
       #[Route('/{id}/reponse', name: 'app_reclamation_reponse_show', methods: ['GET'])]
        public function showReclamationReponse(Reclamation $reclamation, ReponseRepository $reponseRepository, Request $request): Response
        {
            // Retrieve the response associated with the given reclamation
            $reponse = $reponseRepository->findOneBy(['relation' => $reclamation]);

            // Check if a response is found
            if (!$reponse) {
                throw $this->createNotFoundException('No response found for this reclamation.');
            }

            // Create the form
            $form = $this->createForm(ReponseType::class, $reponse);

            // Render the template with the response data and the form
            return $this->render('reponse/showForUser.html.twig', [
                'reponse' => $reponse,
                'reclamation' => $reclamation, // Pass the Reclamation entity to the template
                'form' => $form->createView(), // Pass the form variable to the template
            ]);
        }


















     #[Route('/{id}/reponse', name: 'app_reclamation_reponse_show2', methods: ['GET'])]
     public function showReclamationReponse2(Reclamation $reclamation, ReponseRepository $reponseRepository, Request $request): Response
     {
         // Retrieve the response associated with the given reclamation
         $reponse = $reponseRepository->findOneBy(['relation' => $reclamation]);

         // Check if a response is found
         if (!$reponse) {
             throw $this->createNotFoundException('No response found for this reclamation.');
         }

         // Create the form
         $form = $this->createForm(ReponseType::class, $reponse);

         // Render the template with the response data and the form
         return $this->render('reponse/show.html.twig', [
             'reponse' => $reponse,
             'reclamation' => $reclamation, // Pass the Reclamation entity to the template
             'form' => $form->createView(), // Pass the form variable to the template
         ]);
     }
    #[Route('/listePdf/download', name:'reclamation_listePdf')]
    public function listePdf(EntityManagerInterface $entityManager): Response
    {
        $reclamations = $entityManager
            ->getRepository(Reclamation::class)
            ->findAll();

        $pdfOptions = new Options();
        $pdfOptions->set('defaultFont', 'Arial');

        // Instantiate Dompdf with our options
        $dompdf = new Dompdf($pdfOptions);

        // Retrieve the HTML generated in our twig file
        $html = $this->renderView('reclamation/listePdf.html.twig', [
            'reclamations' => $reclamations,
        ]);

        // Load HTML to Dompdf
        $dompdf->loadHtml($html);
        // (Optional) Setup the paper size and orientation 'portrait' or 'portrait'
        $dompdf->setPaper('A4', 'portrait');
        // Render the HTML as PDF
        $dompdf->render();

        // Output the generated PDF to Browser (force download)
        return new Response($dompdf->output(), 200, [
            'Content-Type' => 'application/pdf',
            'Content-Disposition' => 'attachment; filename="mypdf.pdf"',
        ]);



    }


    //

    //



    #[Route('/reclamations/date', name:'reclamations_date')]
    public function reclamationsByDate(Request $request,ReclamationRepository $reclamationRepository, PaginatorInterface $paginator): Response
    {
        $reclamations = $reclamationRepository->findByDate();
        $pagination = $paginator->paginate(
            $reclamations, // Données à paginer
            $request->query->getInt('page', 1), // Numéro de page
            10 );// Nombre d'éléments par page
        return $this->render('reclamation/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }


    #[Route('/reclamations/etat', name:'reclamations_etat')]

    public function reclamationsByEtat(Request $request, PaginatorInterface $paginator,ReclamationRepository $reclamationRepository): Response
    {
        $reclamations = $reclamationRepository->findByEtat();
        $pagination = $paginator->paginate(
            $reclamations, // Données à paginer
            $request->query->getInt('page', 1), // Numéro de page
            10 // Nombre d'éléments par page
        );
        return $this->render('reclamation/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }


    #[Route('/reclamations/type', name:'reclamations_type')]

    public function reclamationsByType(Request $request, PaginatorInterface $paginator,ReclamationRepository $reclamationRepository): Response
    {
        $reclamations = $reclamationRepository->findByType();
        $pagination = $paginator->paginate(
            $reclamations, // Données à paginer
            $request->query->getInt('page', 1), // Numéro de page
            10 // Nombre d'éléments par page
        );
        return $this->render('reclamation/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }
    //


    //
    //search
    #[Route('/reclamations/search', name:'reclamations_search')]
    public function searchReclam(Request $request , ReclamationRepository $reclamationRepository): Response
    {
        // $searchTerm = $request->query->get('searchTerm');
        $searchTerm = $request->query->get('searchTerm');
        dump($searchTerm);
        $reclamations = [];

        if ($searchTerm) {
            // If a search term is provided, perform the search
            $reclamations = $reclamationRepository->searchByTerm($searchTerm);
        } else {
            // If no search term provided, retrieve all reclamations
            $reclamations = $reclamationRepository->findAll();
        }

        // Create the search form
        $form = $this->createForm(SearchFormType::class);

        return $this->render('reclamation/index.html.twig', [
            'form' => $form->createView(),
            'reclamations' => $reclamations,
        ]);
    }
}



















