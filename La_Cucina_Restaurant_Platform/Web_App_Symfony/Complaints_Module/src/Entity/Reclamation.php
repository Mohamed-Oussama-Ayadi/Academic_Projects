<?php

namespace App\Entity;

use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;

/**
 * Reclamation
 *
 * @ORM\Table(name="reclamation")
 * @ORM\Entity
 */
class Reclamation
{
    /**
     * @ORM\Id
     * @ORM\GeneratedValue
     * @ORM\Column(type="integer")
     */
    private $id;

    /**
     * @ORM\Column(type="string", length=255)
     * @Assert\NotBlank(message="La description ne peut pas être vide")
     * @Assert\Length(max=255, maxMessage="La description ne peut pas dépasser {{ limit }} caractères")
     */
    private $description;

    /**
     * @ORM\Column(type="boolean")
     */
    private $etat = false;

    /**
     * @ORM\Column(type="datetime")
     * @Assert\NotBlank(message="La date de création est requise")
     * @Assert\Type("\DateTimeInterface")
     */
    private $date_creation;

    /**
     * @ORM\Column(type="string", length=255)
     * @Assert\NotBlank(message="Le type ne peut pas être vide")
     * @Assert\Length(max=255, maxMessage="Le type ne peut pas dépasser {{ limit }} caractères")
     */
    private $type;

    /**
     * @ORM\Column(type="boolean")
     */
    private $generateWithAi = false;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getDescription(): ?string
    {
        return $this->description;
    }

    public function setDescription(?string $description): static
    {
        $this->description = $description;
//
//         return $this;
        // Vérifier si la description contient des mots interdits
        $descriptionCleaned = $this->filterBadWords($description);

        // Affecter la description nettoyée
        $this->description = $descriptionCleaned;

        return $this;



        // return $this;
    }






//

//


    private function filterBadWords(string $description): string
    {
        // Read the list of bad words from the text file
        $badWords = file('C:\Users\kassem\Reeclamation\src\Entity\badwords.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

        // Convertir la description en minuscules pour éviter les correspondances de casse
        $descriptionLowercase = strtolower($description);

        // Remplacer les mots interdits par des astérisques
        foreach ($badWords as $badWord) {
            $descriptionLowercase = str_ireplace($badWord, str_repeat('*', strlen($badWord)), $descriptionLowercase);
        }

        // Retourner la description nettoyée
        return $descriptionLowercase;
    }

    /*private function filterBadWords(string $description): string
     {
         // Implement your logic to filter out bad words from the description
         // You can use libraries, regular expressions, or any other method you prefer

         // For demonstration, let's assume you have a list of bad words to filter out
         $badWords = ['bad', 'words', 'here'];

         // Replace bad words with asterisks (*) in the description
         foreach ($badWords as $word) {
             $description = str_ireplace($word, '***', $description);
         }

         return $description;
     }**/

    public function isEtat(): ?bool
    {
        return $this->etat;
    }

    public function setEtat(bool $etat): static
    {
        $this->etat = $etat;

        return $this;
    }

    public function getDateCreation(): ?\DateTimeInterface
    {
        return $this->date_creation;
    }
    public function __construct()
    {
        $this->date_creation = new \DateTime();
    }
    public function setDateCreation(\DateTimeInterface $date_creation): static
    {
        // $this->date_creation = $date_creation;
        if ($this->$date_creation === null) {
            $this->$date_creation = new \DateTime();
        }

        return $this;
    }
    public function getType(): ?string
    {
        return $this->type;
    }

    public function setType(string $type): static
    {
        $this->type = $type;

        return $this;
    }

    public function isGenerateWithAi(): ?bool
    {
        return $this->generateWithAi;
    }

    public function setGenerateWithAi(bool $generateWithAi): static
    {
        $this->generateWithAi = $generateWithAi;

        return $this;
    }


}
