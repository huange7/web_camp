package com.My_login.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public interface RegisterService {
    public void RegisterCheck(String username, String password, HttpServletRequest request, HttpServletResponse response)throws Exception;
}
