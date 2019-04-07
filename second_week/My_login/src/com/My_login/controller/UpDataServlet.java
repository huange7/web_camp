package com.My_login.controller;

import com.My_login.Dao.BasicOperation;
import com.My_login.Dao.Impl.BasicOperationImpl;
import com.My_login.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/UpDataServlet")
public class UpDataServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            String username = request.getParameter("username");
            int status =Integer.parseInt(request.getParameter("status"));
            User user = new User();
            user.setName(username);
            user.setStatus(status);
            BasicOperationImpl basicOperation = new BasicOperationImpl();
        try {
            basicOperation.updateUser(user);
        } catch (Exception e) {
            e.printStackTrace();
        }
        response.sendRedirect("/My_login_war_exploded/UpdataSuccess.jsp");
    }
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            doPost(request,response);
    }
}
