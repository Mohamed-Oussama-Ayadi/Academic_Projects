<?php

namespace App\Form;
use App\Entity\Tables; // Import the Tables entity

use App\Entity\Reservations;
use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolver;
use Symfony\Bridge\Doctrine\Form\Type\EntityType;
use Symfony\Component\Form\Extension\Core\Type\DateType;
use Doctrine\ORM\EntityManagerInterface;
use Doctrine\ORM\EntityRepository;
class ReservationsType extends AbstractType
{
    private $entityManager;

    public function __construct(EntityManagerInterface $entityManager)
    {
        $this->entityManager = $entityManager;
    }
    public function buildForm(FormBuilderInterface $builder, array $options): void
    {
        $builder
            ->add('nbrPersonnes')
            ->add('date', DateType::class, [
                'widget' => 'single_text', // Renders as a single text input
                'label' => 'Date',
                'format' => 'yyyy-MM-dd', // Set the desired format
                // You can customize more options here if needed
            ])
            ->add('horaire')
            ->add('numTab', EntityType::class, [
                'class' => Tables::class,
                'choice_label' => 'numerotable',
               
            ])
        ;
    }

    public function configureOptions(OptionsResolver $resolver): void
    {
        $resolver->setDefaults([
            'data_class' => Reservations::class,
        ]);
    }
}