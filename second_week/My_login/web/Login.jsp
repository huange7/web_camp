<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2019/4/5/005
  Time: 12:48
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%session.invalidate(); %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
    <title>欢迎登陆酒店管理系统！</title>
    <link rel="stylesheet" type="text/css" href="css/Login.css" />
    <script type="text/javascript" src="js/login.js"></script>
</head>
<body>
<body style="background:url(image/login.jpg) ;background-size:cover; ">
<center>
    <div id = "div1">
        <h1 style="color: #1a6c65bf;margin: 152px;font-size: -webkit-xxx-large;">
            <center>
                - 酒店管理系统 -
            </center>
        </h1>
    </div>
    <div id="main">
        <h1>用户登录</h1>
        <form name = "form1"  action = "servlet/LoginServlet" method = "post" onsubmit="return checkInput()">
            <p>
                <span>&nbsp;帐&nbsp;号&nbsp;：</span><input type="text" name = "username">
            </p>
            <p>
                <span>&nbsp;密&nbsp;码&nbsp;：</span><input type="password" name = "password">
            </p>
            <p>
                <br>
                <button class = "button1" type="submit">立即登录</button>
            </p>
            <table align="center">
                <tr>
                    <a href="Register.jsp">注册账户</a>
                    </td>
                </tr>
            </table>
        </form>
    </div>
</center>

</body>
</html>
