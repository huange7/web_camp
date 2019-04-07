package com.My_login.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * @author
 */
public class DbUtil {
    private static String url = "jdbc:mysql://localhost:3306/db_hotel?useSSL=true";
    private static String username = "root";
    private static String password = "123456";
    private static String jdbcname = "com.mysql.jdbc.Driver";

    /**
     * 连接数据库
     * @return
     */
    public Connection getCon() {
        try {
            Class.forName(jdbcname);

        } catch (ClassNotFoundException e) {
            System.out.println("加载数据库连接失败");
            e.printStackTrace();
        }
        Connection con = null;
        try {
            con = DriverManager.getConnection(url, username, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return con;
    }
    public void close(PreparedStatement pstmt, Connection conn) {
        if (pstmt != null) {
            try {
                pstmt.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

    }
}
