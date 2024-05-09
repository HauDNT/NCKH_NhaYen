<?php

$hostname = "localhost";
$username = "root";
$password = "";
$database = "sensors_parameters";

$conn = mysqli_connect($hostname, $username, $password, $database);
if(!$conn) {
    die("Connection failed: " . mysqli_connect_error);
}
echo "Database connection is OK";

if(isset($_POST["temperature"]) && isset($_POST["humidity"]) && isset($_POST["fire"]) && isset($_POST["air"])) {
    $temperature = $_POST["temperature"];
    $humidity = $_POST["humidity"];
    $fire = $_POST["fire"];
    $air = $_POST["air"];
    $sql = "INSERT INTO dht_11 (Temperature, Humidity, Fire, Air) VALUES (".$temperature.", ".$humidity.", ".$fire.", ".$air.")";

    if(mysqli_query($conn, $sql)) {
        echo "<br>" ."New record created successfully";
    } else {
        echo "Error" .$sql ."<br>" .mysqli_error($conn);
    }
}
?>