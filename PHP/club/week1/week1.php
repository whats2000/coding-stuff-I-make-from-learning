<?php
    $arr1 = ["pig", "dog", "cat"];
    print_r($arr1);

    $arr1 = array("pig", "dog", "cat");
    print_r($arr1);

    $arr1[2] = "pig";
    $arr1[0] = "dog";
    print_r($arr1);

    $arr2 = array("pig"=>"apple", "dog"=>"orange");
    print_r($arr2);

    $arr2["cat"] = "banana";
    print_r($arr2);

    for($i = 0; $i < count($arr1) ; $i++){
        echo $arr1[$i]."<br>"; //印出value
    }

    foreach($arr2 as $key=>$val){
        echo "key:".$key."<br>"; 
        echo "val:".$val."<br>";
    }

    // 單雙引號變化
    echo "<p>單雙引號變化</p>";
    $var1 = '123';
    $var2 = "456";

    echo "$var1$var2<br>";
    echo '$var1'."$var2<br>";
    echo "'$var1$var2'<br>";
    echo '"$var1$var2"<br>';


    // multi-array

    echo "<br>multi-array<br>";

    $arr[0][0] = "A";
    $arr[0][1] = "D";
    $arr[1][0] = "B";

    $arr[0] = array("A", "D", "G");
    $arr[1] = array("B", "E", "H");
    $arr[2] = array("C", "F", "I");

    print_r($arr);

    $arr = array(
        array("A", "D", "G"),
        array("B", "E", "H"),
        array("C", "F", "I"),
    );

    print_r($arr);

    $student_info = array(
        "Height" => array("Tom"=>"188", "Amy"=>"158", "Anna"=>"165"),
        "Weight" => array("Tom"=>"68", "Amy"=>"45", "Anna"=>"48"),
    );
    print_r($student_info);

    $student_info["Height"] = array("Tom"=>"188", "Amy"=>"158", "Anna"=>"165");
    $student_info["Weight"] = array("Tom"=>"68", "Amy"=>"45", "Anna"=>"48");
    print_r($student_info);

    echo "<p>另一種寫法</p>";
    $student_info = array();
    $student_info["Tom"] = array("Height"=>"188", "Weight"=>"68");
    $student_info["Amy"] = array("Height"=>"158", "Weight"=>"45");
    $student_info["Anna"] = array("Height"=>"165", "Weight"=>"48");
    print_r($student_info);

    // array_push 實作
    echo "<p>array push 實作 </p>";

    $arr1 = array("a", "b", "c", "d");
    array_push($arr1, "new_value");
    print_r($arr1);
    
    $new_array = array("n", "e" , "w");
    array_push($arr, $new_array);
    print_r($arr);

    // array_pop
    echo "<p>array pop 實作 </p>";
    $data = array_pop($arr1);
    echo "the pop data is :".$data."<br>";
    print_r($arr1);


    $data = array_pop($arr);
    echo "<p>the pop data is :";
    print_r($data);
    echo "</p>";
    print_r($arr);

?>
