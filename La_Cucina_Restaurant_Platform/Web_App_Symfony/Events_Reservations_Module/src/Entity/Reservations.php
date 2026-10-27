<?php

namespace App\Entity;

use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;
/**
 * Reservations
 *
 * @ORM\Table(name="reservations", indexes={@ORM\Index(name="numroTable", columns={"num_tab"}), @ORM\Index(name="idUtilisateur", columns={"idUtilisateur"})})
 * @ORM\Entity
 */
class Reservations
{
    /**
     * @var int
     *
     * @ORM\Column(name="id_reservation", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $idReservation;

    /**
     * @var int|null
     *
     * @ORM\Column(name="nbr_personnes", type="integer", nullable=true)
     * @Assert\NotBlank(message="Le nombre de personnes est obligatoire.")
     * @Assert\PositiveOrZero(message="Le nombre de personnes doit être un nombre positif ou nul.")
     */
    private $nbrPersonnes;

    /**
     * @var \DateTime|null
     *
     * @ORM\Column(name="date", type="date", nullable=true)
     * @Assert\NotBlank(message="La date est obligatoire.")
     * @Assert\GreaterThan("today", message="La date doit être ultérieure à aujourd'hui.")
     */
    private $date;

    /**
     * @var string|null
     *
     * @ORM\Column(name="horaire", type="string", length=255, nullable=true)
     * @Assert\NotBlank(message="L'horaire est obligatoire.")
     * @Assert\Length(max=255, maxMessage="L'horaire ne peut pas dépasser {{ limit }} caractères.")
     */
    private $horaire;

    /**
     * @var \Tables
     *
     * @ORM\ManyToOne(targetEntity="Tables")
     * @ORM\JoinColumns({
     *   @ORM\JoinColumn(name="num_tab", referencedColumnName="numeroTable")
     * })
     */
    private $numTab;

    public function getIdReservation(): ?int
    {
        return $this->idReservation;
    }

    public function getNbrPersonnes(): ?int
    {
        return $this->nbrPersonnes;
    }

    public function setNbrPersonnes(?int $nbrPersonnes): static
    {
        $this->nbrPersonnes = $nbrPersonnes;

        return $this;
    }

    public function getDate(): ?\DateTimeInterface
    {
        return $this->date;
    }
   
    public function setDate(?\DateTimeInterface $setDate): static
    {
        $this->date = $setDate;

        return $this;
    }

    public function getHoraire(): ?string
    {
        return $this->horaire;
    }

    public function setHoraire(?string $horaire): static
    {
        $this->horaire = $horaire;

        return $this;
    }



    public function getNumTab(): ?Tables
    {
        return $this->numTab;
    }

    public function setNumTab(?Tables $numTab): static
    {
        $this->numTab = $numTab;

        return $this;
    }


}
