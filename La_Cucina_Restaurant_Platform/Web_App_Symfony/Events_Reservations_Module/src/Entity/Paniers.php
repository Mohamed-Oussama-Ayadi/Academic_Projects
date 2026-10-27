<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Paniers
 *
 * @ORM\Table(name="paniers", indexes={@ORM\Index(name="user", columns={"idUser"})})
 * @ORM\Entity
 */
class Paniers
{
    /**
     * @var int
     *
     * @ORM\Column(name="idPanier", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $idpanier;

    /**
     * @var bool
     *
     * @ORM\Column(name="isConfirmed", type="boolean", nullable=false)
     */
    private $isconfirmed = '0';

    /**
     * @var float
     *
     * @ORM\Column(name="total", type="float", precision=10, scale=0, nullable=false)
     */
    private $total;

    /**
     * @var \Utilisateurs
     *
     * @ORM\ManyToOne(targetEntity="Utilisateurs")
     * @ORM\JoinColumns({
     *   @ORM\JoinColumn(name="idUser", referencedColumnName="idUtilisateur")
     * })
     */
    private $iduser;

    public function getIdpanier(): ?int
    {
        return $this->idpanier;
    }

    public function isIsconfirmed(): ?bool
    {
        return $this->isconfirmed;
    }

    public function setIsconfirmed(bool $isconfirmed): static
    {
        $this->isconfirmed = $isconfirmed;

        return $this;
    }

    public function getTotal(): ?float
    {
        return $this->total;
    }

    public function setTotal(float $total): static
    {
        $this->total = $total;

        return $this;
    }

    public function getIduser(): ?Utilisateurs
    {
        return $this->iduser;
    }

    public function setIduser(?Utilisateurs $iduser): static
    {
        $this->iduser = $iduser;

        return $this;
    }


}
