<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Administrateurs
 *
 * @ORM\Table(name="administrateurs")
 * @ORM\Entity
 */
class Administrateurs
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
