import java.util.Properties;

import javax.mail.Message;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

import org.apache.log4j.Logger;

public class mail {
    private static final Logger LOGGER = Logger.getLogger(mail.class);
    static String host = "smtp.gmail.com"; // 发送邮件服务器
    static String from = "Jiangxincheng2010@gmail.com"; // 邮件服务器登录用户名,发送人邮件地址
    static String password = "sqzsecs5715935"; // 邮件服务器登录密码

    public static void send(String subject, String content, String[] to) {
        try {
            Properties props = new Properties();
            props.put("mail.smtp.host", host);
            props.put("mail.smtp.auth", "true");

            props.setProperty("mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory");
            props.setProperty("mail.smtp.socketFactory.fallback", "false");
            props.setProperty("mail.smtp.port", "465"); // gmail使用465
            props.setProperty("mail.smtp.socketFactory.port", "465");
            Session ssn = Session.getInstance(props, null);
            MimeMessage message = new MimeMessage(ssn);
            InternetAddress fromAddress;
            fromAddress = new InternetAddress(from);
            message.setFrom(fromAddress);
            InternetAddress[] toAddress = new InternetAddress[to.length];
            for (int i = 0; i < to.length; i++) {
                toAddress[i] = new InternetAddress(to[i]);
            }
            for (int i = 0; i < toAddress.length; i++) {
                message.addRecipient(Message.RecipientType.TO, toAddress[i]);
            }
            message.setSubject(subject);
            message.setText(content);
            Transport transport = ssn.getTransport("smtp");
            transport.connect(host, from, password);
            transport.sendMessage(message, message.getRecipients(Message.RecipientType.TO));
            transport.close();
            LOGGER.info("send mail success!");
        } catch (Throwable e) {
            LOGGER.info("send mail failed", e);
        }
    }

public static void main(String[] args) {
        send("主题", "邮件正文内容", new String[]{"jxcjxcjzx@sina.com","jxcjzxjxc@163.com","jxc@sina.com"});
    }

}
 

