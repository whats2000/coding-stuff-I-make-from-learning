-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- 主機： 127.0.0.1
-- 產生時間： 2022-04-26 15:09:05
-- 伺服器版本： 10.4.22-MariaDB
-- PHP 版本： 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫: `php_course`
--

-- --------------------------------------------------------

--
-- 資料表結構 `photo`
--

CREATE TABLE `photo` (
  `pid` int(11) NOT NULL,
  `mid` int(11) NOT NULL,
  `src` varchar(100) NOT NULL,
  `title` text NOT NULL,
  `description` varchar(500) NOT NULL,
  `hidden` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 傾印資料表的資料 `photo`
--

INSERT INTO `photo` (`pid`, `mid`, `src`, `title`, `description`, `hidden`) VALUES
(1, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test1', 'For test usage', 0),
(2, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test2', 'For test usage', 0),
(3, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test3', 'For test usage', 0),
(4, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test4', 'For test usage', 0);

--
-- 已傾印資料表的索引
--

--
-- 資料表索引 `photo`
--
ALTER TABLE `photo`
  ADD PRIMARY KEY (`pid`);

--
-- 在傾印的資料表使用自動遞增(AUTO_INCREMENT)
--

--
-- 使用資料表自動遞增(AUTO_INCREMENT) `photo`
--
ALTER TABLE `photo`
  MODIFY `pid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
