package com.My_login.service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @author huange7
 */
public interface LoginService {
    /**
     * 检测用户输入方法
     * @param username
     * @param password
     * @param request
     * @param response
     */
    public void loginCheck(String username, String password , HttpServletRequest request, HttpServletResponse response) throws Exception;
}
