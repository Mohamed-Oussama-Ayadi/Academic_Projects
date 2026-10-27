<?php

namespace App\Entity;

use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

/**
 * Evenements
 *
 * @ORM\Table(name="evenements", indexes={@ORM\Index(name="idUtilisateur", columns={"idUtilisateur"})})
 * @ORM\Entity
 */
class Evenements
{
    /**
     * @var int
     *
     * @ORM\Column(name="id_event", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $idEvent;

    /**
     * @var string|null
     *
     * @ORM\Column(name="nom_event", type="string", length=255, nullable=true)
     */
    private $nomEvent;

    /**
     * @var \DateTime|null
     *
     * @ORM\Column(name="date_event", type="date", nullable=true)
     */
    private $dateEvent;

    /**
     * @var \DateTime|null
     *
     * @ORM\Column(name="heure_event", type="time", nullable=true)
     */
    private $heureEvent;

    /**
     * @var string|null
     *
     * @ORM\Column(name="description_event", type="string", length=255, nullable=true)
     */
    private $descriptionEvent;

    /**
     * @var \Utilisateurs
     *
     * @ORM\ManyToOne(targetEntity="Utilisateurs")
     * @ORM\JoinColumns({
     *   @ORM\JoinColumn(name="idUtilisateur", referencedColumnName="idUtilisateur")
     * })
     */
    private $idutilisateur;

    /**
     * @var \Doctrine\Common\Collections\Collection
     *
     * @ORM\ManyToMany(targetEntity="Utilisateurs", inversedBy="idEvent")
     * @ORM\JoinTable(name="userevent",
     *   joinColumns={
     *     @ORM\JoinColumn(name="id_event", referencedColumnName="id_event")
     *   },
     *   inverseJoinColumns={
     *     @ORM\JoinColumn(name="id_utilisateur", referencedColumnName="idUtilisateur")
     *   }
     * )
     */
    private $idUtilisateur = array();

    /**
     * Constructor
     */
    public function __construct()
    {
        $this->idUtilisateur = new \Doctrine\Common\Collections\ArrayCollection();
    }

    public function getIdEvent(): ?int
    {
        return $this->idEvent;
    }

    public function getNomEvent(): ?string
    {
        return $this->nomEvent;
    }

    public function setNomEvent(?string $nomEvent): static
    {
        $this->nomEvent = $nomEvent;

        return $this;
    }

    public function getDateEvent(): ?\DateTimeInterface
    {
        return $this->dateEvent;
    }

    public function setDateEvent(?\DateTimeInterface $dateEvent): static
    {
        $this->dateEvent = $dateEvent;

        return $this;
    }

    public function getHeureEvent(): ?\DateTimeInterface
    {
        return $this->heureEvent;
    }

    public function setHeureEvent(?\DateTimeInterface $heureEvent): static
    {
        $this->heureEvent = $heureEvent;

        return $this;
    }

    public function getDescriptionEvent(): ?string
    {
        return $this->descriptionEvent;
    }

    public function setDescriptionEvent(?string $descriptionEvent): static
    {
        $this->descriptionEvent = $descriptionEvent;

        return $this;
    }

    public function getIdutilisateur(): ?Utilisateurs
    {
        return $this->idutilisateur;
    }

    public function setIdutilisateur(?Utilisateurs $idutilisateur): static
    {
        $this->idutilisateur = $idutilisateur;

        return $this;
    }

    public function addIdUtilisateur(Utilisateurs $idUtilisateur): static
    {
        if (!$this->idUtilisateur->contains($idUtilisateur)) {
            $this->idUtilisateur->add($idUtilisateur);
        }

        return $this;
    }

    public function removeIdUtilisateur(Utilisateurs $idUtilisateur): static
    {
        $this->idUtilisateur->removeElement($idUtilisateur);

        return $this;
    }

}
