-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 01, 2024 at 05:30 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sensors_parameters`
--
CREATE DATABASE IF NOT EXISTS `sensors_parameters` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE `sensors_parameters`;

-- --------------------------------------------------------

--
-- Table structure for table `dht_11`
--

CREATE TABLE `dht_11` (
  `ID` int(11) NOT NULL,
  `Temperature` int(11) NOT NULL,
  `Humidity` int(11) NOT NULL,
  `Fire` tinyint(1) NOT NULL,
  `Air` float NOT NULL,
  `Datetime` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `dht_11`
--

INSERT INTO `dht_11` (`ID`, `Temperature`, `Humidity`, `Fire`, `Air`, `Datetime`) VALUES
(1, 28, 61, 1, 90.39, '2024-02-01 11:27:26'),
(2, 28, 61, 1, 90.97, '2024-02-01 11:27:32'),
(3, 28, 61, 1, 90.95, '2024-02-01 11:27:37'),
(4, 28, 61, 1, 90.99, '2024-02-01 11:27:42'),
(5, 28, 61, 1, 91.03, '2024-02-01 11:27:47');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `dht_11`
--
ALTER TABLE `dht_11`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `dht_11`
--
ALTER TABLE `dht_11`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
