-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : dim. 26 juin 2022 à 12:17
-- Version du serveur : 5.7.36
-- Version de PHP : 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `mabase`
--

-- --------------------------------------------------------

--
-- Structure de la table `historique`
--

DROP TABLE IF EXISTS `historique`;
CREATE TABLE IF NOT EXISTS `historique` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Datedarrive` datetime NOT NULL,
  `Datedesortie` datetime DEFAULT NULL,
  `id_users` int(20) DEFAULT NULL,
  `id_place` int(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `fk_idplace` (`id_place`),
  UNIQUE KEY `fk_idUser` (`id_users`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `historique`
--

INSERT INTO `historique` (`id`, `Datedarrive`, `Datedesortie`, `id_users`, `id_place`) VALUES
(2, '2022-06-25 22:31:24', '2022-06-25 22:31:27', NULL, NULL),
(3, '2022-06-25 22:35:19', NULL, 1, 2);

-- --------------------------------------------------------

--
-- Structure de la table `parking`
--

DROP TABLE IF EXISTS `parking`;
CREATE TABLE IF NOT EXISTS `parking` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `libelle` varchar(20) NOT NULL,
  `id_users` int(11) DEFAULT NULL,
  `EstReserver` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_users` (`id_users`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `parking`
--

INSERT INTO `parking` (`id`, `libelle`, `id_users`, `EstReserver`) VALUES
(1, '01', NULL, 0),
(2, '02', NULL, 0),
(3, '03', NULL, 0);

-- --------------------------------------------------------

--
-- Structure de la table `types`
--

DROP TABLE IF EXISTS `types`;
CREATE TABLE IF NOT EXISTS `types` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `libelle` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `types`
--

INSERT INTO `types` (`id`, `libelle`) VALUES
(1, 'Administrateur'),
(2, 'Client');

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `id` int(50) NOT NULL AUTO_INCREMENT,
  `id_type` int(11) NOT NULL,
  `pseudo` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `Immac` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_type` (`id_type`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`id`, `id_type`, `pseudo`, `password`, `Immac`) VALUES
(1, 1, 'admin', '21232f297a57a5a743894a0e4a801fc3', '3333'),
(4, 2, 'rafiki', 'ab4f63f9ac65152575886860dde480a1', ''),
(5, 2, 'lolo', '8054da645a387dbfb06654d69f0d0201', ''),
(9, 2, 'lola', '8054da645a387dbfb06654d69f0d0201', ''),
(10, 2, 'eleve', 'c16da4ad70df593520193184381b9f21', 'aaaaa');

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `historique`
--
ALTER TABLE `historique`
  ADD CONSTRAINT `historique_ibfk_1` FOREIGN KEY (`id_place`) REFERENCES `parking` (`id`),
  ADD CONSTRAINT `historique_ibfk_2` FOREIGN KEY (`id_users`) REFERENCES `users` (`id`);

--
-- Contraintes pour la table `parking`
--
ALTER TABLE `parking`
  ADD CONSTRAINT `parking_ibfk_1` FOREIGN KEY (`id_users`) REFERENCES `users` (`id`);

--
-- Contraintes pour la table `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `users_ibfk_1` FOREIGN KEY (`id_type`) REFERENCES `types` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
