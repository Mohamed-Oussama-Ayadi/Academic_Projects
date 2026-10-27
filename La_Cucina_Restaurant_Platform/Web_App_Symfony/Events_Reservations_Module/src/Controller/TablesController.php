<?php

namespace App\Controller;

use App\Entity\Tables;
use App\Form\TablesType;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

#[Route('/tables')]
class TablesController extends AbstractController
{
    #[Route('/', name: 'app_tables_index', methods: ['GET'])]
    public function index(EntityManagerInterface $entityManager): Response
    {
        $tables = $entityManager
            ->getRepository(Tables::class)
            ->findAll();

        return $this->render('tables/index.html.twig', [
            'tables' => $tables,
        ]);
    }

    #[Route('/new', name: 'app_tables_new', methods: ['GET', 'POST'])]
    public function new(Request $request, EntityManagerInterface $entityManager): Response
    {
        $table = new Tables();
        $form = $this->createForm(TablesType::class, $table);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($table);
            $entityManager->flush();

            return $this->redirectToRoute('app_tables_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->renderForm('tables/new.html.twig', [
            'table' => $table,
            'form' => $form,
        ]);
    }

    #[Route('/{numerotable}', name: 'app_tables_show', methods: ['GET'])]
    public function show(Tables $table): Response
    {
        return $this->render('tables/show.html.twig', [
            'table' => $table,
        ]);
    }

    #[Route('/{numerotable}/edit', name: 'app_tables_edit', methods: ['GET', 'POST'])]
    public function edit(Request $request, Tables $table, EntityManagerInterface $entityManager): Response
    {
        $form = $this->createForm(TablesType::class, $table);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();

            return $this->redirectToRoute('app_tables_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->renderForm('tables/edit.html.twig', [
            'table' => $table,
            'form' => $form,
        ]);
    }

    #[Route('/{numerotable}', name: 'app_tables_delete', methods: ['POST'])]
    public function delete(Request $request, Tables $table, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete'.$table->getNumerotable(), $request->request->get('_token'))) {
            $entityManager->remove($table);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_tables_index', [], Response::HTTP_SEE_OTHER);
    }
}
