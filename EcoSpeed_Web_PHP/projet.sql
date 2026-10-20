-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 07 mai 2022 à 11:51
-- Version du serveur : 10.4.22-MariaDB
-- Version de PHP : 7.4.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `projet`
--

-- --------------------------------------------------------

--
-- Structure de la table `boutiques`
--

CREATE TABLE `boutiques` (
  `id` int(6) NOT NULL,
  `adresse` varchar(20) NOT NULL,
  `email` varchar(30) NOT NULL,
  `nbre_voitures` int(11) NOT NULL,
  `nbre_pieces_rechange` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `boutiques`
--

INSERT INTO `boutiques` (`id`, `adresse`, `email`, `nbre_voitures`, `nbre_pieces_rechange`) VALUES
(1, 'ariana', 'm1@gmail.com', 300, 150),
(2, 'djerba', 'm2@gmail.com', 200, 50),
(3, 'nabeul', 'm3@gmail.com', 200, 150),
(4, 'tunis', 'm4@gmail.com', 90, 300),
(5, 'sfax', 'm5@gmail.com', 60, 250),
(6, 'nabeul', 'm6@gmail.com', 200, 100),
(7, 'nabeul', 'm7@gmail.com', 300, 255),
(8, 'tunis', 'm8@gmail.com', 200, 175),
(9, 'djerba', 'm9@gmail.com', 250, 200),
(10, 'sfax', 'm10@gmail.coom', 200, 135);

-- --------------------------------------------------------

--
-- Structure de la table `categories`
--

CREATE TABLE `categories` (
  `id_categorie` int(6) NOT NULL,
  `nom` varchar(25) NOT NULL,
  `type` varchar(25) NOT NULL,
  `stock_max` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `categories`
--

INSERT INTO `categories` (`id_categorie`, `nom`, `type`, `stock_max`) VALUES
(9, 'Pièces de rechanges', 'Hybride', 600),
(10, 'Voitures', 'Hybride', 350),
(13, 'X', 'Hybride', 1);

-- --------------------------------------------------------

--
-- Structure de la table `facture`
--

CREATE TABLE `facture` (
  `reference` int(11) NOT NULL,
  `id_station` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `matricule` varchar(10) NOT NULL,
  `montant` int(11) NOT NULL,
  `date_paiement` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `facture`
--

INSERT INTO `facture` (`reference`, `id_station`, `id_user`, `matricule`, `montant`, `date_paiement`) VALUES
(6, 122, 4421, '455tun789', 201, '2022-04-06'),
(17, 122, 222, '555tun555', 22, '2222-02-22'),
(30, 129, 8897, '55tun12', 99, '2022-04-20'),
(31, 121, 6641, '100tun220', 330, '2022-04-05'),
(34, 129, 7777, '444tun444', 10000, '2022-04-05');

-- --------------------------------------------------------

--
-- Structure de la table `ouvriers`
--

CREATE TABLE `ouvriers` (
  `id` int(6) NOT NULL,
  `nom` varchar(20) NOT NULL,
  `prenom` varchar(20) NOT NULL,
  `age` int(11) NOT NULL,
  `departement` varchar(20) NOT NULL,
  `email` varchar(30) NOT NULL,
  `id_boutique` int(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `ouvriers`
--

INSERT INTO `ouvriers` (`id`, `nom`, `prenom`, `age`, `departement`, `email`, `id_boutique`) VALUES
(1, 'a', 'a', 40, 'rh', 'm1@gmail.com', 1),
(2, 'b', 'b', 28, 'marketing', 'm2@gmail.com', 2),
(3, 'c', 'c', 22, 'financier', 'm3@gmail.com', 3),
(4, 'd', 'd', 33, 'marketing', 'm4@gmail.com', 4),
(5, 'f', 'f', 40, 'marketing', 'm5@gmail.com', 5),
(6, 'l', 'l', 43, 'rh', 'm6@gmail.com', 6),
(7, 'z', 'z', 22, 'financier', 'm7@gmail.com', 7),
(8, 'i', 'i', 43, 'marketing', 'm8@gmail.com', 8),
(9, 'x', 'x', 54, 'marketing', 'm9@gmail.com', 9),
(10, 'm', 'm', 21, 'rh', 'm10@gmail.coom', 10);

-- --------------------------------------------------------

--
-- Structure de la table `produits`
--

CREATE TABLE `produits` (
  `id_produit` int(6) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `marque` varchar(20) NOT NULL,
  `photo` varchar(255) NOT NULL,
  `description` text NOT NULL,
  `prix` float NOT NULL,
  `quantite` int(100) NOT NULL,
  `like` int(100) DEFAULT NULL,
  `id_categorie` int(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `produits`
--

INSERT INTO `produits` (`id_produit`, `nom`, `marque`, `photo`, `description`, `prix`, `quantite`, `like`, `id_categorie`) VALUES
(36, 'Peugeot 3008 Hybrid', 'Peugeot', 'produit/images/Peugeot.png', 'Motorisation :Hybride rechargeable  Catégorie: SUV  Places :5', 139000000, 4, NULL, 10),
(37, 'Volkswagen Tiguan ', 'Volkswagen', 'produit/images/Volks.png', 'Sous le capot, on retrouve un moteur essence 1.4 l TSI de 150 chevaux couplé à un bloc électrique de 85 kW (116 ch). L’ensemble cumule 245 chevaux, soit 180 kW. En matière de performances, le constructeur annonce 205 km/h de vitesse maximale et un 0 à 100 km/h abattu en 7.5 secondes.', 168000000, 1, NULL, 10),
(38, 'Chargeur Voiture Hybride', 'Hybride', 'produit/images/chargeur.png', 'Puissance:7,4 KW', 700, 20, NULL, 9),
(40, 'Toyota C-HR', 'Toyota', 'produit/images/Toyota.png', 'Climatisation automatique bizone Détecteur de pluie et allumage automatique des phares  Écran tactile 8” avec système multimédia Toyota Touch 2 et caméra de recul  Jantes alliage 17”  Ordinateur de bord avec écran TFT couleur 4,2” multifonction  Projecteurs antibrouillard  Sellerie tissu gris foncé  Volant cuir', 98600000, 3, NULL, 10),
(41, 'Poste Radio Peugeot 5008', 'Peugeot', 'produit/images/radio.png', 'Autoradio Peugeot 5008 - Android 8.0 - GPS intégré - DVD/DIVX - WiFi - 3G - PIP - POP - TMC - Bluetooth (Parrot) - Récupération du répertoire - Appels mains libres - Chargeur virtuel - iPod/iPhone - Commandes aux volants - MirrorLink - SD - Radio avec RDS - USB - Caméra de recul - RK PX5 8 coeurs 1.66 Ghz - Ecran tactile - Double zone - TV numérique - DVR - AUX - MP3 - Vidéo 1080PCadeaux : Caméra de recul étanche HD et Cartographie GPS Europe 2021 en 3D', 1300, 15, NULL, 9);

-- --------------------------------------------------------

--
-- Structure de la table `station`
--

CREATE TABLE `station` (
  `id` int(11) NOT NULL,
  `ville` varchar(20) NOT NULL,
  `energie` int(11) NOT NULL,
  `nombre_voiture` int(11) NOT NULL,
  `rentabilite` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `station`
--

INSERT INTO `station` (`id`, `ville`, `energie`, `nombre_voiture`, `rentabilite`) VALUES
(121, 'Bizerte', 22, 22, 22),
(122, 'Sousse', 445, 56, 32),
(129, 'Tunis', 222, 35, 60),
(131, 'Sfax', 223, 561, 65),
(132, 'Tunis', 320, 430, 50),
(133, 'Sfax', 650, 450, 70),
(134, 'Tunis', 300, 440, 23),
(135, 'Bizerte', 30, 160, 51),
(136, 'Bizerte', 30, 160, 51),
(137, 'Sousse', 220, 200, 65),
(138, 'Sousse', 220, 200, 65),
(139, 'tunis', 100, 100, 10);

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `Id_user` int(6) NOT NULL,
  `Nom` varchar(20) NOT NULL,
  `Prenom` varchar(30) NOT NULL,
  `Age` int(25) NOT NULL,
  `Ville` varchar(25) NOT NULL,
  `Num_tel` int(12) NOT NULL,
  `Email` varchar(80) NOT NULL,
  `Role` varchar(25) NOT NULL,
  `password` varchar(60) NOT NULL,
  `img` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`Id_user`, `Nom`, `Prenom`, `Age`, `Ville`, `Num_tel`, `Email`, `Role`, `password`, `img`) VALUES
(14, 'Ines', 'Azer', 20, 'tu', 12345678, 'ines@gmail.com', 'Administrateur', '12345678', '../uploads/download.jpg'),
(15, 'Ines', 'Mh', 23, 'nabeul', 12345645, 'inesmahjoubi68@gmail.com', 'Administrateur', '59971fced76bc6c5171f95de077fd659', '../uploads/Screenshot_20200415-213931_Instagram.jpg'),
(16, 'Jihen', 'Dok', 23, 'sousse', 12345645, 'ines@gmail.com', 'User', 'ab4f63f9ac65152575886860dde480a1', '../uploads/Screenshot_20200415-213936_Instagram.jpg'),
(17, 'mariem', 'marsaoui', 21, 'tunis', 90133184, 'mariem.marsaoui@esprit.tn', 'Administrateur', '123456789', '');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `boutiques`
--
ALTER TABLE `boutiques`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `categories`
--
ALTER TABLE `categories`
  ADD PRIMARY KEY (`id_categorie`);

--
-- Index pour la table `facture`
--
ALTER TABLE `facture`
  ADD PRIMARY KEY (`reference`),
  ADD KEY `id_station` (`id_station`);

--
-- Index pour la table `ouvriers`
--
ALTER TABLE `ouvriers`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_ouvriers` (`id_boutique`);

--
-- Index pour la table `produits`
--
ALTER TABLE `produits`
  ADD PRIMARY KEY (`id_produit`),
  ADD KEY `FK_categorie_produit` (`id_categorie`);

--
-- Index pour la table `station`
--
ALTER TABLE `station`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`Id_user`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `boutiques`
--
ALTER TABLE `boutiques`
  MODIFY `id` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pour la table `categories`
--
ALTER TABLE `categories`
  MODIFY `id_categorie` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT pour la table `facture`
--
ALTER TABLE `facture`
  MODIFY `reference` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;

--
-- AUTO_INCREMENT pour la table `ouvriers`
--
ALTER TABLE `ouvriers`
  MODIFY `id` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pour la table `produits`
--
ALTER TABLE `produits`
  MODIFY `id_produit` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=42;

--
-- AUTO_INCREMENT pour la table `station`
--
ALTER TABLE `station`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=140;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `Id_user` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `facture`
--
ALTER TABLE `facture`
  ADD CONSTRAINT `id_station` FOREIGN KEY (`id_station`) REFERENCES `station` (`id`);

--
-- Contraintes pour la table `ouvriers`
--
ALTER TABLE `ouvriers`
  ADD CONSTRAINT `fk_ouvriers` FOREIGN KEY (`id_boutique`) REFERENCES `boutiques` (`id`);

--
-- Contraintes pour la table `produits`
--
ALTER TABLE `produits`
  ADD CONSTRAINT `FK_categorie_produit` FOREIGN KEY (`id_categorie`) REFERENCES `categories` (`id_categorie`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
