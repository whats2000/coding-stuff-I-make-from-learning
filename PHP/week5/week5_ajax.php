<?php
    $dbh = new PDO('mysql:host=localhost;dbname=php_course;charset=utf8', 'php_course', '123456789');

    $sql = "SELECT * FROM `account` WHERE `STUID` = :stuid";

    exit(json_encode(array("status"=>"ok")));
