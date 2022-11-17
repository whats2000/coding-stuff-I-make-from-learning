<?php
    $arr = array("apple"=>"red", "banana"=>"yellow", "guava"=>"green");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>第一周作業</title>
</head>
<body>
    <?php
        $student_info["Tom"] = array("Height"=>"188", "Weight"=>"68");
        $student_info["Amy"] = array("Height"=>"158", "Weight"=>"45");
        $student_info["Anna"] = array("Height"=>"165", "Weight"=>"48");

        foreach ($student_info as $key=>$val) {
            $student_info_c["Height"][$key] = $val["Height"];
            $student_info_c["Weight"][$key] = $val["Weight"];
            $student_info_c["BMI"][$key] = $val["Height"] / ($val["Weight"] * $val["Weight"]);
        }
    ?>

    <table border="1">
        <tr>
            <td></td>
            <?php foreach ($student_info as $key=>$val) { ?>
                <td><?=$key?></td>
            <?php } ?> 
        </tr>

        <?php foreach ($student_info_c as $key=>$val) { ?>
            <tr>
                <td><?=$key?></td>

                <?php foreach ($student_info as $key1=>$val1) { ?>
                    <td><?=$student_info_c[$key][$key1]?></td>
                <?php } ?> 
            </tr>
        <?php } ?>
    </table>
</body>
</html>