<?php

namespace App\Form;

use App\Entity\Reclamation;
use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\Extension\Core\Type\ChoiceType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolver;
use Symfony\Component\Validator\Constraints\Length;
use Symfony\Component\Validator\Constraints\NotBlank;

class ReclamationType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options): void
    {
        $builder
            ->add('description', null, [
                'constraints' => [
                    new NotBlank([
                        'message' => 'Veuillez entrer une description.',
                    ]),
                    new Length([
                        'max' => 255,
                        'maxMessage' => 'La description ne peut pas dépasser {{ limit }} caractères.',
                    ]),
                ],

            ])
            ->add('type', ChoiceType::class, [
                'constraints' => [
                    new NotBlank([
                        'message' => 'Veuillez choisir un type de réclamation.',
                    ]),
                ],
                'choices' => [
                    'Publication non visible sur la plateforme ' => 'Publication non visible sur la plateforme',
                    'Difficulté à publier du contenu ' => 'Difficulté à publier du contenu',
                    'Difficulté à trouver des collaborations appropriées' => 'Difficulté à trouver des collaborations appropriées',
                    'Problèmes de communication avec les collaborateurs' => 'Problèmes de communication avec les collaborateurs',
                    'Difficulté à utiliser certaines fonctionnalités de l \'application' => 'Difficulté à utiliser certaines fonctionnalités de l \'application',
                    'Violation des conditions d\'utilisation de la plateforme' => 'Violation des conditions d\'utilisation de la plateforme',
                    'Besoin d\'assistance pour résoudre des problèmes liés au compte' => 'Besoin d\'assistance pour résoudre des problèmes liés au compte',

                ],
                'placeholder' => 'Choisir le type de réclamation',
                'required' => true,
            ]);
    }

    public function configureOptions(OptionsResolver $resolver): void
    {
        $resolver->setDefaults([
            'data_class' => Reclamation::class,
        ]);
    }
}
