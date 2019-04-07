package com.My_login.Dao.Impl;

import com.My_login.Dao.UserDao;
import com.My_login.model.User;
import com.My_login.util.DbUtil;
import com.My_login.util.MD5Util;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author huange7
 */
public class UserDaoImpl implements UserDao {
    private static DbUtil dbUtil = new DbUtil();
    boolean flat = false;

    @Override
    public boolean update(User user, String newPassword) throws Exception {
        Connection con = dbUtil.getCon();
        PreparedStatement pstmt = null;
        int result = 0;
        try {
            String sql = "update db_user set password=? where username=?";
            pstmt = con.prepareStatement(sql);
            pstmt.setString(1, newPassword);
            pstmt.setString(2, user.getName());
            result = pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, con);
        }

        if (result != 0) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public boolean addUser(User user) throws Exception {
        Connection con = dbUtil.getCon();
        PreparedStatement pstmt = null;
        int t = 0;
        try {
            String sql = "insert into db_user(username, password, status)values(?, ?, ?)";
            user.setPassword(MD5Util.getMD5String(user.getPassword()));
            pstmt = con.prepareStatement(sql);
            pstmt.setString(1, user.getName());
            pstmt.setString(2, user.getPassword());
            pstmt.setInt(3, user.getStatus());
            t = pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, con);
        }
        if (t != 0) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public boolean usernameIsExist(String username) throws Exception {
        Connection con = dbUtil.getCon();
        PreparedStatement pstmt = null;
        try {
            String sql = "select * from db_user where username=?";
            pstmt = con.prepareStatement(sql);
            pstmt.setString(1, username);

            if (!pstmt.executeQuery().next()) {
                return false;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, con);
        }
        return true;
    }

    @Override
    public boolean LoginRight(String username, String password) throws Exception {
        boolean t = false;
        Connection con = dbUtil.getCon();
        password = MD5Util.getMD5String(password);
        PreparedStatement pstmt = null;
        String sql = "select * from db_user";
        try {
            pstmt = con.prepareStatement(sql);
            ResultSet rs = pstmt.executeQuery();
            while (rs.next()) {
                if (username.equals(rs.getString("username")) && password.equals(rs.getString("password"))) {
                    t = true;
                    break;
                }
            }
        } catch (SQLException e1) {
            e1.printStackTrace();
        } finally {
            dbUtil.close(pstmt, con);
        }

        return t;
    }

    @Override
    public int judgeStatus(String username) throws Exception {
        Connection con = dbUtil.getCon();
        int status = 1;
        PreparedStatement pstmt = null;
        try {
            String sql = "select * from db_user";
            pstmt = con.prepareStatement(sql);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()){
                if(username.equals(rs.getString("username"))){
                    status = rs.getInt("status");
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            dbUtil.close(pstmt, con);
        }
        return status;
    }
}
