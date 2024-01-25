<?php
$hostname = 'localhost';
$username = 'root';
$password = '';
$database = 'sensors_parameters';

$connect = mysqli_connect($hostname, $username, $password, $database);
if (!$connect) {
    die('Connection failed! Detail: ' . mysqli_connect_error());
}

echo 'Connect successful!';

if (isset($_POST["temperature"]) && isset($_POST["humidity"])) {
    $temperature = $_POST["temperature"];
    $humidity = $_POST["humidity"];

    $sql = "INSERT INTO dht_11 (Temperature, Humidity) VALUES (" . $temperature . "," . $humidity . ")";

    if (mysqli_query($connect, $sql)) {
        echo 'Insert successfully!';
    } else {
        echo 'Insert failed. Detail: ' . mysqli_error($connect);
    }
}
