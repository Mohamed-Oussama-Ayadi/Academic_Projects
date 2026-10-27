<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Commandes
 *
 * @ORM\Table(name="commandes")
 * @ORM\Entity
 */
class Commandes
{
    /**
     * @var int
     *
     * @ORM\Column(name="id_commande", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $idCommande;

    /**
     * @var string
     *
     * @ORM\Column(name="date_commande", type="string", length=100, nullable=false)
     */
    private $dateCommande;

    /**
     * @var float
     *
     * @ORM\Column(name="montant_total", type="float", precision=10, scale=0, nullable=false)
     */
    private $montantTotal;

    /**
     * @var string
     *
     * @ORM\Column(name="mode_paiement", type="string", length=100, nullable=false)
     */
    private $modePaiement;

    public function getIdCommande(): ?int
    {
        return $this->idCommande;
    }

    public function getDateCommande(): ?string
    {
        return $this->dateCommande;
    }

    public function setDateCommande(string $dateCommande): static
    {
        $this->dateCommande = $dateCommande;

        return $this;
    }

    public function getMontantTotal(): ?float
    {
        return $this->montantTotal;
    }

    public function setMontantTotal(float $montantTotal): static
    {
        $this->montantTotal = $montantTotal;

        return $this;
    }

    public function getModePaiement(): ?string
    {
        return $this->modePaiement;
    }

    public function setModePaiement(string $modePaiement): static
    {
        $this->modePaiement = $modePaiement;

        return $this;
    }


}
