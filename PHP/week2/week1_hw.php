<?php

    $student_info = array();
    $student_info["Tom"] = array("Height"=>"188", "Weight"=>"68");
    $student_info["Amy"] = array("Height"=>"158", "Weight"=>"45");
    $student_info["Anna"] = array("Height"=>"165", "Weight"=>"48");

    foreach($student_info as $name=>$arr){
        $bmi = $arr["Weight"] / ($arr["Height"] * 0.01 * $arr["Height"] * 0.01);
        $arr["BMI"] = $bmi;
        $student_info[$name] = $arr;
    }


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
    <table border="1">
        <tr>
            <td></td>
            <td>Height</td>
            <td>Weight</td>
            <td>BMI</td>
        </tr>
        <?php foreach($student_info as $key=>$val){?>
                <tr>
                    <td><?=$key?></td>
                    <td><?=$val["Height"]?></td>
                    <td><?=$val["Weight"]?></td>
                    <td><?=$val["BMI"]?></td>

                </tr>
        <?php    }
        ?>
    </table>
</body>
</html>