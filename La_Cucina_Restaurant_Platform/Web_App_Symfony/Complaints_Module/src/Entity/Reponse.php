<?php

namespace App\Entity;

use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

/**
 * Reponse
 *
 * @ORM\Table(name="reponse", uniqueConstraints={@ORM\UniqueConstraint(name="UNIQ_5FB6DEC7100D1FDF", columns={"id_reclamation_id"})})
 * @ORM\Entity
 */
class Reponse
{
    /**
     * @var int
     *
     * @ORM\Column(name="id", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $id;

    /**
     * @var string
     *
     * @ORM\Column(name="reponse", type="string", length=255, nullable=false)
     */
    private $reponse;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_reponse", type="datetime", nullable=false)
     */
    private $dateReponse;

    /**
     * @var \Reclamation
     *
     * @ORM\ManyToOne(targetEntity="Reclamation")
     * @ORM\JoinColumns({
     *   @ORM\JoinColumn(name="id_reclamation_id", referencedColumnName="id")
     * })
     */
    private $relation = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getReponse(): ?string
    {
        return $this->reponse;
    }

    public function setReponse(string $reponse): static
    {
        $this->reponse = $reponse;

        return $this;
    }

    public function getDateReponse(): ?\DateTimeInterface
    {
        return $this->dateReponse;
    }

    public function setDateReponse(\DateTimeInterface $dateReponse): static
    {
        $this->dateReponse = $dateReponse;

        return $this;
    }

    public function getRelation(): ?Reclamation
    {
        return $this->relation;
    }

    public function setRelation(?Reclamation $relation): static
    {
        $this->relation = $relation;

        return $this;
    }


}
