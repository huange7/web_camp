<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2019/4/5/005
  Time: 15:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册账号</title>
    <link rel="stylesheet" type="text/css" href="css/Register.css" />
    <script type="text/javascript" src="js/Register.js"></script>
</head>
<body>
<body style="background:url(image/login.jpg) ;background-size:cover; "></body>
<center>
    <h1 id="h1">- 用户注册 -</h1>
    <h4 style="color: #c12f5e;margin: 0px;">
        账号: 7-15位的数字英文组合（首位必须为字母）<br> 密码：6-15位数字
    </h4>
    <div id="reg">
        <h1>用户信息</h1>
        <form   name="form2" action="servlet/RegisterServlet" method="post" onsubmit="return checkInput()">
            <p>
                <span>&nbsp;帐&nbsp;号&nbsp;：</span> <input type="text" name="username"value="">
            </p>
            <p>
                <span> &nbsp;密&nbsp;码&nbsp;：</span> <input type="password" name="password"value="">
            </p>
            <br>
            <p>
                <button class="button" type="submit">立即注册</button>
            </p>
            <a id = "a1" href="Login.jsp">回到首页</a>
        </form>
    </div>
</center>
</body>
</html>
