<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class IndexBackController extends AbstractController
{
    #[Route('/indexBack', name: 'indexBack')]
    public function index(): Response
    {
        return $this->render('index_back/index.html.twig', [
            'controller_name' => 'IndexBackController',
        ]);
    }
}
