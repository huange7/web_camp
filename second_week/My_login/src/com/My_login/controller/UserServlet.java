package com.My_login.controller;

import com.My_login.model.User;
import com.My_login.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/UserServlet")
public class UserServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = (String)request.getSession().getAttribute("username");
        UserServiceImpl userService = new UserServiceImpl();
        try {
            userService.userService(username,request,response);
            request.getSession().setAttribute("username", username);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}