<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous"></script>
    <title>第二周練習</title>
</head>
<body>
    <div class="row justify-content-center">
        <div class="col-sm-4">
            <form action="week2_pact_act.php" method="post">
                <p>金萱雙Q 價格：35</p>
                <label for="num1">請填寫數量</label>
                <input type="number"  min="0" max="10" value="0" id="num1" name="num1">

                <br>
                <br>

                <div class="mb-3">
                    <select name="sugar1" class="form-select form-select mb-3" aria-label=".form-select ">
                        <option selected>請選擇甜度</option>
                        <option value="多糖">多糖</option>
                        <option value="正常糖">正常糖</option>
                        <option value="少糖">少糖</option>
                        <option value="半糖">半糖</option>
                        <option value="微糖">微糖</option>
                        <option value="無糖">無糖</option>
                    </select>
                </div>
                <div class="mb-3">
                    <select name="ice1" class="form-select form-select mb-3" aria-label=".form-select ">
                        <option selected>請選擇冰塊</option>
                        <option value="多冰">多冰</option>
                        <option value="正常冰">正常冰</option>
                        <option value="少冰">少冰</option>
                        <option value="微冰">微冰</option>
                        <option value="去冰">去冰</option>
                    </select>
                </div>

                <p>胭脂紅茶 價格：40</p>
                <label for="num2">請填寫數量</label>
                <input type="number"  min="0" max="10" value="0" id="num2" name="num2">

                <br>
                <br>

                <div class="mb-3">
                    <select name="sugar2" class="form-select form-select mb-3" aria-label=".form-select ">
                        <option selected>請選擇甜度</option>
                        <option value="多糖">多糖</option>
                        <option value="正常糖">正常糖</option>
                        <option value="少糖">少糖</option>
                        <option value="半糖">半糖</option>
                        <option value="微糖">微糖</option>
                        <option value="無糖">無糖</option>
                    </select>
                </div>
                <div class="mb-3">
                    <select name="ice2" class="form-select form-select mb-3" aria-label=".form-select ">
                        <option selected>請選擇冰塊</option>
                        <option value="多冰">多冰</option>
                        <option value="正常冰">正常冰</option>
                        <option value="少冰">少冰</option>
                        <option value="微冰">微冰</option>
                        <option value="去冰">去冰</option>
                    </select>
                </div>

                <p>胭脂多多 價格：50</p>
                <label for="num3">請填寫數量</label>
                <input type="number"  min="0" max="10" value="0" id="num3" name="num3">

                <br>
                <br>

                <div class="mb-3">
                    <select name="sugar3" class="form-select form-select mb-3" aria-label=".form-select ">
                        <option selected>請選擇甜度</option>
                        <option value="多糖">多糖</option>
                        <option value="正常糖">正常糖</option>
                        <option value="少糖">少糖</option>
                        <option value="半糖">半糖</option>
                        <option value="微糖">微糖</option>
                        <option value="無糖">無糖</option>
                    </select>
                </div>
                <div class="mb-3">
                    <select name="ice3" class="form-select form-select mb-3" aria-label=".form-select ">
                        <option selected>請選擇冰塊</option>
                        <option value="多冰">多冰</option>
                        <option value="正常冰">正常冰</option>
                        <option value="少冰">少冰</option>
                        <option value="微冰">微冰</option>
                        <option value="去冰">去冰</option>
                    </select>
                </div>

                <div class="mb-3 ">
                    <label for="name">姓名</label>
                    <input type="text" name="name" id="name">
                </div>

                <div class="mb-3 ">
                    <label for="phone">聯絡電話</label>
                    <input type="text" name="phone" id="phone">
                </div>

                <div class="mb-3 ">
                    <label for="addr">地址</label>
                    <input type="text" name="addr" id="addr">
                </div>

                <div class="mb-3 ">
                    <input type="checkbox" class="form-check-input" id="check" name="check" required>
                    <label class="form-check-label" for="check">以上資料皆正確</label>
                </div>

                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
        </div>
    </div>
    
</body>
</html>