-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 16, 2024 at 04:02 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `environment_control_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `id` int(11) NOT NULL,
  `username` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL,
  `role_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`id`, `username`, `password`, `role_id`) VALUES
(2, 'tienhau', 'tienhau', 1);

-- --------------------------------------------------------

--
-- Table structure for table `messages`
--

CREATE TABLE `messages` (
  `station_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `message` text NOT NULL,
  `time_send` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `position`
--

CREATE TABLE `position` (
  `id` int(11) NOT NULL,
  `Position` varchar(255) NOT NULL,
  `StationId` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `position`
--

INSERT INTO `position` (`id`, `Position`, `StationId`) VALUES
(1, 'Tầng 1', 1),
(2, 'Tầng 2', 1);

-- --------------------------------------------------------

--
-- Table structure for table `roles`
--

CREATE TABLE `roles` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `roles`
--

INSERT INTO `roles` (`id`, `name`) VALUES
(1, 'Quản trị viên'),
(2, 'Nhân viên');

-- --------------------------------------------------------

--
-- Table structure for table `sensors`
--

CREATE TABLE `sensors` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `station_id` int(11) NOT NULL,
  `position_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `sensors`
--

INSERT INTO `sensors` (`id`, `name`, `station_id`, `position_id`) VALUES
(1, 'DHT11', 1, 1),
(2, 'Báo cháy', 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `sensor_values`
--

CREATE TABLE `sensor_values` (
  `sensor_id` int(11) NOT NULL,
  `value` double NOT NULL,
  `unit_id` int(11) NOT NULL,
  `createdAt` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `sensor_values`
--

INSERT INTO `sensor_values` (`sensor_id`, `value`, `unit_id`, `createdAt`) VALUES
(1, 30.4, 3, '2024-05-15 18:49:42'),
(1, 76, 1, '2024-05-15 18:49:42'),
(2, 1, 2, '2024-05-15 18:49:42'),
(1, 30.4, 3, '2024-05-15 18:49:48'),
(1, 76, 1, '2024-05-15 18:49:48'),
(2, 1, 2, '2024-05-15 18:49:48'),
(1, 30.4, 3, '2024-05-15 18:50:03'),
(1, 76, 1, '2024-05-15 18:50:03'),
(2, 1, 2, '2024-05-15 18:50:03'),
(1, 30.4, 3, '2024-05-15 18:50:06'),
(1, 76, 1, '2024-05-15 18:50:06'),
(2, 1, 2, '2024-05-15 18:50:06'),
(1, 30.4, 3, '2024-05-15 18:50:12'),
(1, 76, 1, '2024-05-15 18:50:12'),
(2, 1, 2, '2024-05-15 18:50:12'),
(1, 30.4, 3, '2024-05-15 18:50:19'),
(1, 76, 1, '2024-05-15 18:50:19'),
(2, 1, 2, '2024-05-15 18:50:19'),
(1, 30.4, 3, '2024-05-15 18:50:27'),
(1, 76, 1, '2024-05-15 18:50:27'),
(2, 1, 2, '2024-05-15 18:50:27'),
(1, 30.4, 3, '2024-05-15 18:50:40'),
(1, 76, 1, '2024-05-15 18:50:40'),
(2, 1, 2, '2024-05-15 18:50:40'),
(1, 30.4, 3, '2024-05-15 18:50:50'),
(1, 76, 1, '2024-05-15 18:50:50'),
(2, 1, 2, '2024-05-15 18:50:50'),
(1, 30.3, 3, '2024-05-15 18:51:04'),
(1, 76, 1, '2024-05-15 18:51:04'),
(2, 1, 2, '2024-05-15 18:51:04'),
(1, 30.3, 3, '2024-05-15 18:51:15'),
(1, 76, 1, '2024-05-15 18:51:15'),
(2, 1, 2, '2024-05-15 18:51:15'),
(1, 30.3, 3, '2024-05-15 18:51:32'),
(1, 76, 1, '2024-05-15 18:51:32'),
(2, 1, 2, '2024-05-15 18:51:32'),
(1, 30.3, 3, '2024-05-15 18:51:40'),
(1, 76, 1, '2024-05-15 18:51:40'),
(2, 1, 2, '2024-05-15 18:51:40'),
(1, 30.3, 3, '2024-05-15 18:51:51'),
(1, 76, 1, '2024-05-15 18:51:51'),
(2, 1, 2, '2024-05-15 18:51:51'),
(1, 30.3, 3, '2024-05-15 18:51:59'),
(1, 77, 1, '2024-05-15 18:51:59'),
(2, 1, 2, '2024-05-15 18:51:59'),
(1, 30.3, 3, '2024-05-15 18:52:07'),
(1, 77, 1, '2024-05-15 18:52:07'),
(2, 1, 2, '2024-05-15 18:52:07'),
(1, 30.3, 3, '2024-05-15 18:52:13'),
(1, 76, 1, '2024-05-15 18:52:13'),
(2, 1, 2, '2024-05-15 18:52:13'),
(1, 30.3, 3, '2024-05-15 18:52:19'),
(1, 77, 1, '2024-05-15 18:52:19'),
(2, 1, 2, '2024-05-15 18:52:19');

-- --------------------------------------------------------

--
-- Table structure for table `stations`
--

CREATE TABLE `stations` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `address` text NOT NULL,
  `longtitude` float NOT NULL COMMENT 'Kinh độ',
  `langtitude` float NOT NULL COMMENT 'Vĩ độ',
  `user_id` int(11) NOT NULL COMMENT 'Người phụ trách quản lý'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `stations`
--

INSERT INTO `stations` (`id`, `name`, `address`, `longtitude`, `langtitude`, `user_id`) VALUES
(1, 'Trạm số 1', 'Sô 60, Nguyễn Trung Trực, TP. Rạch Giá, Kiên Giang.', 60, 45.3, 2),
(2, 'Trạm số 2', 'Số 50, đường Mai Thị Hồng Hạnh, Rạch Sỏi, Kiên Giang.', 203.4, 436.4, 2);

-- --------------------------------------------------------

--
-- Table structure for table `units`
--

CREATE TABLE `units` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `units`
--

INSERT INTO `units` (`id`, `name`) VALUES
(1, '%'),
(2, 'Fire'),
(3, '°C');

-- --------------------------------------------------------

--
-- Table structure for table `userinfo`
--

CREATE TABLE `userinfo` (
  `fullname` varchar(200) NOT NULL,
  `birthday` date NOT NULL,
  `email` varchar(100) NOT NULL,
  `phone_number` varchar(20) NOT NULL,
  `gender` tinyint(1) NOT NULL,
  `account_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `userinfo`
--

INSERT INTO `userinfo` (`fullname`, `birthday`, `email`, `phone_number`, `gender`, `account_id`) VALUES
('Đặng Nguyễn Tiền Hậu', '2024-05-01', 'haudnt@gmail.com', '0941000000', 1, 2);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`id`),
  ADD KEY `role_id` (`role_id`);

--
-- Indexes for table `messages`
--
ALTER TABLE `messages`
  ADD KEY `user_id` (`user_id`),
  ADD KEY `station_id` (`station_id`);

--
-- Indexes for table `position`
--
ALTER TABLE `position`
  ADD PRIMARY KEY (`id`),
  ADD KEY `StationId` (`StationId`);

--
-- Indexes for table `roles`
--
ALTER TABLE `roles`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `sensors`
--
ALTER TABLE `sensors`
  ADD PRIMARY KEY (`id`),
  ADD KEY `station_id` (`station_id`),
  ADD KEY `position_id` (`position_id`);

--
-- Indexes for table `sensor_values`
--
ALTER TABLE `sensor_values`
  ADD KEY `sensor_id` (`sensor_id`),
  ADD KEY `unit_id` (`unit_id`);

--
-- Indexes for table `stations`
--
ALTER TABLE `stations`
  ADD PRIMARY KEY (`id`),
  ADD KEY `user_id` (`user_id`);

--
-- Indexes for table `units`
--
ALTER TABLE `units`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `userinfo`
--
ALTER TABLE `userinfo`
  ADD KEY `account_id` (`account_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `position`
--
ALTER TABLE `position`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `roles`
--
ALTER TABLE `roles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `sensors`
--
ALTER TABLE `sensors`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `stations`
--
ALTER TABLE `stations`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `units`
--
ALTER TABLE `units`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `accounts`
--
ALTER TABLE `accounts`
  ADD CONSTRAINT `accounts_ibfk_1` FOREIGN KEY (`role_id`) REFERENCES `roles` (`id`);

--
-- Constraints for table `messages`
--
ALTER TABLE `messages`
  ADD CONSTRAINT `messages_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `accounts` (`id`),
  ADD CONSTRAINT `messages_ibfk_2` FOREIGN KEY (`station_id`) REFERENCES `stations` (`id`);

--
-- Constraints for table `position`
--
ALTER TABLE `position`
  ADD CONSTRAINT `position_ibfk_1` FOREIGN KEY (`StationId`) REFERENCES `stations` (`id`);

--
-- Constraints for table `sensors`
--
ALTER TABLE `sensors`
  ADD CONSTRAINT `sensors_ibfk_2` FOREIGN KEY (`station_id`) REFERENCES `stations` (`id`),
  ADD CONSTRAINT `sensors_ibfk_3` FOREIGN KEY (`position_id`) REFERENCES `position` (`id`);

--
-- Constraints for table `sensor_values`
--
ALTER TABLE `sensor_values`
  ADD CONSTRAINT `sensor_values_ibfk_1` FOREIGN KEY (`sensor_id`) REFERENCES `sensors` (`id`),
  ADD CONSTRAINT `sensor_values_ibfk_2` FOREIGN KEY (`unit_id`) REFERENCES `units` (`id`);

--
-- Constraints for table `stations`
--
ALTER TABLE `stations`
  ADD CONSTRAINT `stations_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `accounts` (`id`);

--
-- Constraints for table `userinfo`
--
ALTER TABLE `userinfo`
  ADD CONSTRAINT `userinfo_ibfk_1` FOREIGN KEY (`account_id`) REFERENCES `accounts` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
