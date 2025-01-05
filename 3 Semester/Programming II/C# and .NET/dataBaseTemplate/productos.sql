-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 26-11-2024 a las 07:43:11
-- Versión del servidor: 10.4.22-MariaDB
-- Versión de PHP: 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `productos`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `prendas`
--

CREATE TABLE `prendas` (
  `id` int(11) NOT NULL,
  `producto` varchar(30) NOT NULL,
  `imagen` varchar(30) NOT NULL,
  `precio` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `prendas`
--

INSERT INTO `prendas` (`id`, `producto`, `imagen`, `precio`) VALUES
(1, 'prenda1', 'prenda1.jpg', 600),
(3, 'prenda3', 'prenda3.jpg', 820),
(4, 'prenda4', 'prenda4.jpg', 925),
(26, 'sueter', 'sueter.jpg', 550),
(51, 'chaleco invierno', 'chaleco.jpg', 600),
(52, 'falda', 'falda.jgp', 562),
(54, 'sudadera roja', 'sudadera.jpg', 720),
(63, 'gabardina', 'gabardina.jpg', 1600);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `prendas`
--
ALTER TABLE `prendas`
  ADD PRIMARY KEY (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
