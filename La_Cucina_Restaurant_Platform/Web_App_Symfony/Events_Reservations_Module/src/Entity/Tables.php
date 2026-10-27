<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;

/**
 * Tables
 *
 * @ORM\Table(name="tables", indexes={@ORM\Index(name="uc_emplacement", columns={"emplacement"})})
 * @ORM\Entity
 */
class Tables
{
    /**
     * @var int
     *
     * @ORM\Column(name="numeroTable", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $numerotable;

    /**
     * @var int|null
     *
     * @ORM\Column(name="capacite", type="integer", nullable=true)
     * @Assert\NotBlank(message="La capacité ne peut pas être vide")
     * @Assert\PositiveOrZero(message="La capacité doit être un nombre positif ou zéro")
     */
    private $capacite;

    /**
     * @var string|null
     *
     * @ORM\Column(name="emplacement", type="string", length=255, nullable=true)
     * @Assert\NotBlank(message="L'emplacement ne peut pas être vide")
     * @Assert\Length(
     *      max = 255,
     *      maxMessage = "L'emplacement ne peut pas dépasser {{ limit }} caractères"
     * )
     */
    private $emplacement;

    /**
     * @var bool|null
     *
     * @ORM\Column(name="disponibilite", type="boolean", nullable=true)
     */
    private $disponibilite;



    public function getNumerotable(): ?int
    {
        return $this->numerotable;
    }

    public function getCapacite(): ?int
    {
        return $this->capacite;
    }

    public function setCapacite(?int $capacite): static
    {
        $this->capacite = $capacite;

        return $this;
    }

    public function getEmplacement(): ?string
    {
        return $this->emplacement;
    }

    public function setEmplacement(?string $emplacement): static
    {
        $this->emplacement = $emplacement;

        return $this;
    }

    public function isDisponibilite(): ?bool
    {
        return $this->disponibilite;
    }

    public function setDisponibilite(?bool $disponibilite): static
    {
        $this->disponibilite = $disponibilite;

        return $this;
    }
}
