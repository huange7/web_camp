<%@page import="com.My_login.model.User"%>
<%@page import="com.My_login.Dao.Impl.BasicOperationImpl"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
    <title>修改用户信息</title>
    <link rel="stylesheet" type="text/css" href="css/Search.css" />
</head>
<%
    String username = (String)request.getParameter("username");
    int status = ( int)request.getSession().getAttribute("status");
    BasicOperationImpl basicOperation = new BasicOperationImpl();
    User user = basicOperation.searchUser(username);
%>
<body>
<body style="background:url(image/User.jpg) ;background-size:cover; "></body>
<form name="form4" method="post" action="servlet/UpDataServlet">

    <table width="388" border="1" class="table1">
        <caption class="cap1">修改用户信息<br>
        </caption>
        <tr>
            <td width="165" height="42" align="right">用&nbsp;&nbsp;&nbsp;户&nbsp;&nbsp;&nbsp;名 ：</td>
            <td width="207">
                <input type="text" name="username" id="name" value="<%=user.getName()%>" class = "input1"></td>
        </tr>
        <tr>
            <td height="57" align="right">身&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 份：</td>
            <td>
                <p id= "p1">
                    <select required class="select1" name = "status">
                        <%
                            if(status >= 3){
                        %>
                        <option value="3">超级管理员</option>
                        <%
                            }
                        %>
                        <%
                            if(status >= 2){
                        %>
                        <option value="2">管理员</option>
                        <%
                            }
                        %>
                        <option value="1">普通用户</option>
                    </select>
                </p>
            </td>
        </tr>
        <tr>
            <td height="100" colspan="2" align="center">
                <input type="submit" name="OK" value="提交" class="input">
                &nbsp;&nbsp;&nbsp;&nbsp; &nbsp;
                <input type="reset" name="Cancel"  value="重置" class="input"></td>
            </td>
        </tr>
    </table>
</form>
</body>
</html>