<?php include('./predefined.php');?>
<!DOCTYPE html>
<html lang="en">

<head>
    <title>IN-CLASS ASSIGNMENT</title>
</head>

<body>
    <h1>whats2000</h1>

    <h3>Year is "<?=$year?>"</h3>

    <h3>3rd of word in paragraph is "<?=explode(' ', $para)[2]?>"</h3>

    <h3>Random number from predefined is "<?=$random_number?>"</h3>

    <h3>String from getStringValue is "<?=getStringValue()?>"</h3>
</body>

</html>