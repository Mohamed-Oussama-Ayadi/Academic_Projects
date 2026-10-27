<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Clients
 *
 * @ORM\Table(name="clients")
 * @ORM\Entity
 */
class Clients
{
    /**
     * @var \Utilisateurs
     *
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="NONE")
     * @ORM\OneToOne(targetEntity="Utilisateurs")
     * @ORM\JoinColumns({
     *   @ORM\JoinColumn(name="idUtilisateur", referencedColumnName="idUtilisateur")
     * })
     */
    private $idutilisateur;

    public function getIdutilisateur(): ?Utilisateurs
    {
        return $this->idutilisateur;
    }

    public function setIdutilisateur(?Utilisateurs $idutilisateur): static
    {
        $this->idutilisateur = $idutilisateur;

        return $this;
    }


}
