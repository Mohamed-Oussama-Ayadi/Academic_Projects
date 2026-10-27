<?php

namespace App\Controller;

use App\Entity\Reservations;
use App\Form\ReservationsType;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;
use Knp\Component\Pager\PaginatorInterface;
use Dompdf\Dompdf;
use Dompdf\Options;
use Symfony\Component\OptionsResolver\OptionsResolver;
use Symfony\Component\Mailer\MailerInterface;
use Symfony\Component\Mime\Email;

#[Route('/reservations')]
class ReservationsController extends AbstractController
{
   
    #[Route('/', name: 'app_reservations_index', methods: ['GET'])]
    public function index(EntityManagerInterface $entityManager, PaginatorInterface $paginator, Request $request): Response
    {
        $query = $entityManager->getRepository(Reservations::class)->createQueryBuilder('r')
        ->getQuery();

    $pagination = $paginator->paginate(
        $query,
        $request->query->getInt('page', 1), // Current page number
        3 // Items per page
    );

    return $this->render('reservations/index.html.twig', [
        'pagination' => $pagination,
    ]);
        
    }
   
    #[Route('/new', name: 'app_reservations_new', methods: ['GET', 'POST'])]
    public function new(Request $request, EntityManagerInterface $entityManager,MailerInterface $mailer): Response
    {
        $reservation = new Reservations();
        $form = $this->createForm(ReservationsType::class, $reservation);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $formData = $form->getData();

    // Convert the 'date' property from DateTime object to string
    $dateAsString = $formData->getDate()->format('Y-m-d');
            $entityManager->persist($reservation);
            $entityManager->flush();
            $this->validateEmail($request,$mailer);
            flash()->addSuccess('Reservation added successfully');
            return $this->redirectToRoute('app_reservations_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->renderForm('reservations/new.html.twig', [
            'reservation' => $reservation,
            'form' => $form,
        ]);
    }
    #[Route('/ll', name: 'll')]
    public function validateEmail(Request $request, MailerInterface $mailer): Response
    {
       
        
        $message = (new Email())
            ->from('mohamedoussamaayadi@esprit.tn')
            ->to('kassem.benhenda@esprit.tn')
            ->subject('Hello')
            ->text('reservation ajoute');
    
        $mailer->send($message);
    
        return new Response('Message sent.');
     

        dump('code23');
    }
    #[Route('/{idReservation}', name: 'app_reservations_show', methods: ['GET'])]
    public function show(Reservations $reservation): Response
    {
        return $this->render('reservations/show.html.twig', [
            'reservation' => $reservation,
        ]);
    }

    #[Route('/{idReservation}/edit', name: 'app_reservations_edit', methods: ['GET', 'POST'])]
    public function edit(Request $request, Reservations $reservation, EntityManagerInterface $entityManager): Response
    {
        $form = $this->createForm(ReservationsType::class, $reservation);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();

            return $this->redirectToRoute('app_reservations_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->renderForm('reservations/edit.html.twig', [
            'reservation' => $reservation,
            'form' => $form,
        ]);
    }

    #[Route('/{idReservation}', name: 'app_reservations_delete', methods: ['POST'])]
    public function delete(Request $request, Reservations $reservation, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete'.$reservation->getIdReservation(), $request->request->get('_token'))) {
            $entityManager->remove($reservation);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_reservations_index', [], Response::HTTP_SEE_OTHER);
    }
    /**
     * @Route("/tables/sort-by-date", name="app_tables_sort_by_date")
     */
    public function sortByDate(Request $request, PaginatorInterface $paginator,EntityManagerInterface $entityManager): Response
    {
   /*     $query = $this->getDoctrine()
        ->getRepository(Reservations::class)
        ->createQueryBuilder('r')
        ->orderBy('r.date', 'ASC')
        ->getQuery();

    // Paginate the query
    $pagination = $paginator->paginate(
        $query, // Query to paginate
        $request->query->getInt('page', 1), // Page number, defaults to 1 if not provided
        10 // Items per page
    );

    return $this->render('reservations/index.html.twig', [
        'pagination' => $pagination,
    ]);*/
    $currentDate = new \DateTime();

    // Créez une requête pour récupérer les réservations du jour
    $query = $this->getDoctrine()
        ->getRepository(Reservations::class)
        ->createQueryBuilder('r')
        ->where('r.date = :currentDate')
        ->setParameter('currentDate', $currentDate->format('Y-m-d'))
        ->orderBy('r.date', 'ASC')
        ->getQuery();

    // Paginate the query
    $pagination = $paginator->paginate(
        $query, // Query to paginate
        $request->query->getInt('page', 1), // Page number, defaults to 1 if not provided
        10 // Items per page
    );
    $this->listePdf($entityManager);
    return $this->render('reservations/index.html.twig', [
        'pagination' => $pagination,
    ]);
    }
    /**
     * @Route("/tables/sort-by-horaire", name="app_tables_sort_by_horaire")
     */
    public function sortByhoraire(Request $request, PaginatorInterface $paginator): Response
    {
        // Fetch all reservations sorted by horaire
    $query = $this->getDoctrine()
    ->getRepository(Reservations::class)
    ->createQueryBuilder('r')
    ->orderBy('r.horaire', 'desc')
    ->getQuery();

// Paginate the query
$pagination = $paginator->paginate(
    $query, // Query to paginate
    $request->query->getInt('page', 1), // Page number, defaults to 1 if not provided
    10 // Items per page
);

return $this->render('reservations/index.html.twig', [
    'pagination' => $pagination,
]);
    }













    #[Route('/listePdf/download', name:'reservations_listePdf')]
    public function listePdf(EntityManagerInterface $entityManager): Response
    {
        $reservations = $entityManager
            ->getRepository(Reservations::class)
            ->findAll();

        $pdfOptions = new Options();
        $pdfOptions->set('defaultFont', 'Arial');

        // Instantiate Dompdf with our options
        $dompdf = new Dompdf($pdfOptions);

        // Retrieve the HTML generated in our twig file
        $html = $this->renderView('reservations/listePdf.html.twig', [
            'reservations' => $reservations,
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

/*
    #[Route('/reclamations/date', name:'reclamations_date')]
    public function reclamationsByDate(Request $request,ReservationsRepository $reclamationRepository, PaginatorInterface $paginator): Response
    {
        $reclamations = $reclamationRepository->findByDate();
        $pagination = $paginator->paginate(
            $reclamations, // Données à paginer
            $request->query->getInt('page', 1), // Numéro de page
            10 );// Nombre d'éléments par page
        return $this->render('reservations/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }


    #[Route('/reclamations/etat', name:'reclamations_etat')]

    public function reclamationsByEtat(Request $request, PaginatorInterface $paginator,ReservationsRepository $reclamationRepository): Response
    {
        $reclamations = $reclamationRepository->findByEtat();
        $pagination = $paginator->paginate(
            $reclamations, // Données à paginer
            $request->query->getInt('page', 1), // Numéro de page
            10 // Nombre d'éléments par page
        );
        return $this->render('reservations/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }


    #[Route('/reclamations/type', name:'reclamations_type')]

    public function reclamationsByType(Request $request, PaginatorInterface $paginator,ReservationsRepository $reclamationRepository): Response
    {
        $reclamations = $reclamationRepository->findByType();
        $pagination = $paginator->paginate(
            $reclamations, // Données à paginer
            $request->query->getInt('page', 1), // Numéro de page
            10 // Nombre d'éléments par page
        );
        return $this->render('reservations/index.html.twig', [
            'reclamations' => $pagination,
        ]);
    }

*/

}
