<?php
$id = 0;
$name = "";

$db = new PDO("mysql:dbname=imdb_assignment;host=localhost", "root", "");
if (isset($_POST["submit-button"])) {
    $id = $_POST["id"];
    $name = $_POST["name"];

    $target = $db->query("SELECT * FROM movies WHERE id = '$id';");
    if ($target->rowCount() == 1) {
        if ($db->exec("UPDATE movies SET name = '$name' WHERE id = '$id'")) {
            echo '<script>console.log("Database update successfully")</script>';
        } else {
            echo '<script>console.log("Database update fail")</script>';
        }
    } else {
        echo '<script>console.log("The id is not found")</script>';
    }
}
$rank_8_movies = $db->query("SELECT * FROM movies WHERE rank = 8 ORDER BY year LIMIT 3;");
$id_09_movies = $db->query("SELECT * FROM movies 
                            INNER JOIN movies_genres ON movies.id = movies_genres.movie_id 
                            WHERE movies_genres.genre = 'action' AND movies.id LIKE '%09' LIMIT 3");
?>

<!DOCTYPE html>
<html>

<head>
    <title>imdb_assignment</title>
</head>

<body>
    <?php if ($rank_8_movies->rowCount() > 0) {?>
    <table>
        <tr>
            <td>Name</td>
            <td>Rank</td>
            <td>Year</td>
        </tr>
        <?php foreach ($rank_8_movies as $movie) {?>
        <tr>
            <td><?= $movie["name"] ?></td>
            <td><?= $movie["year"] ?></td>
            <td><?= $movie["rank"] ?></td>
        </tr>
        <?php }?>
    </table>
    <?php } else { ?>
    <p>no movies match</p>
    <?php }?>
    <hr>

    <?php if ($id_09_movies->rowCount() > 0) {?>
    <table>
        <tr>
            <td>id</td>
            <td>Name</td>
            <td>Genre</td>
        </tr>
        <?php foreach ($id_09_movies as $movie) {?>
        <tr>
            <td><?= $movie["id"] ?></td>
            <td><?= $movie["name"] ?></td>
            <td><?= $movie["genre"] ?></td>
        </tr>
        <?php }?>
    </table>
    <?php } else { ?>
    <p>no movies match</p>
    <?php }?>
    <form action="<?=$_SERVER['PHP_SELF'] ?>" method="post">
        Change Name of movie with id:
        <input type="number" name="id" style="width: 85px;" />
        to :
        <input type="text" name="name" />
        <button type="submit" name="submit-button">Change</button>
    </form>
</body>

</html>