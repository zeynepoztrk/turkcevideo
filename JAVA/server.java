/*
 *
 *        ^
 *       /^\\
 *      /___\\         YILDIZ ROKET TAKIMI
 *     |=   =|
 *     |     |        Olusturulma Tarihi     : 2025-05-16 12:10:11
 *     |     |        Son Guncellenme Tarihi : 2025-05-25 17:00:11
 *     |     |
 *    /|##!##|\\
 *   / |##!##| \\
 *  /  |##!##|  \\
 * |  / ^ | ^ \  |                                       YILDIZDAN
 * | /  ( | )  \ |
 * |/   ( | )   \|                                                                YILDIZLARA
 *     ((   ))
 *    ((  :  ))
 *    ((  :  ))
 *     ((   ))
 *      (( ))
 *       ( )
 *
 *
 * ************************************************************************************
 */


import java.io.*;
import java.net.*;

public class server {



    private static final int BUFFER_SIZE = 1024;
    private static final int TIMEOUT = 30000;                                   // 30 saniye bağlanmazsa server kapatılacaktır

    public static void main(String[] args) {
        int PORT = 45000;


        ServerSocket SSOKET = null;
        try {
            SSOKET = new ServerSocket(PORT);
            SSOKET.setSoTimeout(TIMEOUT);                                       // Bağlantı bekleme timeout'u
            System.out.println("Server başlatıldı, port:" + PORT);

            while (true) {
                try (Socket clientSocket = SSOKET.accept();
                     InputStream in = clientSocket.getInputStream();
                     BufferedReader reader = new BufferedReader(new InputStreamReader(in))) {

                    System.out.println("Client bağlandı: " + clientSocket.getInetAddress());
                    clientSocket.setSoTimeout(TIMEOUT); // Veri bekleme timeout'u

                    String line;
                    while ((line = reader.readLine()) != null) {
                        System.out.println("Alınan veri: " + line);
                        // Veri işleme kodları buraya
                    }

                }
                System.out.println("Client bağlantısı sonlandı, yeni bağlantı bekleniyor...");
            }

        }
        catch (IOException e) {
            System.err.println("Server hatası: " + e.getMessage());
        }
        finally {
            if (SSOKET != null) {
                try {
                    SSOKET.close();
                } catch (IOException e) {
                    System.err.println("Server socket kapatılırken hata: " + e.getMessage());
                }
            }
        }
    }
}
