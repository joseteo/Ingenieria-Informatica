/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package practica2smm;

/**
 *
 * @author joset
 */
public class VentanaPrincipal extends javax.swing.JFrame {

    /**
     * Creates new form VentanaPrincipal
     */
    public VentanaPrincipal() {
        initComponents();
        this.setSize(800, 800);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jSplitPane5 = new javax.swing.JSplitPane();
        jPanel1 = new javax.swing.JPanel();
        jSplitPane3 = new javax.swing.JSplitPane();
        jTabbedPane2 = new javax.swing.JTabbedPane();
        Projects1 = new javax.swing.JPanel();
        Practica2SMM2 = new javax.swing.JTree();
        Files1 = new javax.swing.JPanel();
        Practica2SMM3 = new javax.swing.JTree();
        Services1 = new javax.swing.JPanel();
        jDesktopPane2 = new javax.swing.JDesktopPane();
        jInternalFrame2 = new javax.swing.JInternalFrame();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        Navigator = new javax.swing.JPanel();
        Practica2SMM = new javax.swing.JTree();
        jPanel3 = new javax.swing.JPanel();
        jSplitPane1 = new javax.swing.JSplitPane();
        jTabbedPane5 = new javax.swing.JTabbedPane();
        Output = new javax.swing.JPanel();
        textArea2 = new java.awt.TextArea();
        jSplitPane2 = new javax.swing.JSplitPane();
        jTabbedPane4 = new javax.swing.JTabbedPane();
        Properties = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jList1 = new javax.swing.JList<>();
        Palette = new javax.swing.JPanel();
        jToolBar1 = new javax.swing.JToolBar();
        jTabbedPane3 = new javax.swing.JTabbedPane();
        Archivos = new javax.swing.JPanel();
        textArea1 = new java.awt.TextArea();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenu2 = new javax.swing.JMenu();
        jMenu3 = new javax.swing.JMenu();
        jMenu4 = new javax.swing.JMenu();
        jMenu5 = new javax.swing.JMenu();
        jMenu6 = new javax.swing.JMenu();
        jMenu7 = new javax.swing.JMenu();
        jMenu8 = new javax.swing.JMenu();
        jMenu9 = new javax.swing.JMenu();
        jMenu10 = new javax.swing.JMenu();
        jMenu11 = new javax.swing.JMenu();
        jMenu12 = new javax.swing.JMenu();
        jMenu13 = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setLayout(new java.awt.BorderLayout());

        jSplitPane3.setOrientation(javax.swing.JSplitPane.VERTICAL_SPLIT);

        Projects1.setLayout(new java.awt.BorderLayout());
        Projects1.add(Practica2SMM2, java.awt.BorderLayout.CENTER);

        jTabbedPane2.addTab("Projects", Projects1);

        Files1.setLayout(new java.awt.BorderLayout());

        Practica2SMM3.setToolTipText("");
        Files1.add(Practica2SMM3, java.awt.BorderLayout.CENTER);

        jTabbedPane2.addTab("Files", Files1);

        Services1.setLayout(new java.awt.BorderLayout());

        jInternalFrame2.setVisible(true);

        javax.swing.GroupLayout jInternalFrame2Layout = new javax.swing.GroupLayout(jInternalFrame2.getContentPane());
        jInternalFrame2.getContentPane().setLayout(jInternalFrame2Layout);
        jInternalFrame2Layout.setHorizontalGroup(
            jInternalFrame2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jInternalFrame2Layout.setVerticalGroup(
            jInternalFrame2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );

        jDesktopPane2.add(jInternalFrame2);
        jInternalFrame2.setBounds(0, -144, 800, 140);

        Services1.add(jDesktopPane2, java.awt.BorderLayout.PAGE_END);

        jTabbedPane2.addTab("Services", Services1);

        jSplitPane3.setLeftComponent(jTabbedPane2);

        Navigator.setLayout(new java.awt.BorderLayout());
        Navigator.add(Practica2SMM, java.awt.BorderLayout.CENTER);
        Practica2SMM.getAccessibleContext().setAccessibleName("");
        Practica2SMM.getAccessibleContext().setAccessibleDescription("");

        jTabbedPane1.addTab("Navigator", Navigator);

        jSplitPane3.setRightComponent(jTabbedPane1);

        jPanel1.add(jSplitPane3, java.awt.BorderLayout.CENTER);

        jSplitPane5.setLeftComponent(jPanel1);

        jPanel3.setLayout(new java.awt.BorderLayout());

        jSplitPane1.setOrientation(javax.swing.JSplitPane.VERTICAL_SPLIT);

        Output.setLayout(new java.awt.BorderLayout());

        textArea2.setText("/*  * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license  * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template  */ package practica2smm;  /**  *  * @author joset  */ public class Practica2SMM {      public static void main(String args[]) {         /* Set the Nimbus look and feel */         //<editor-fold defaultstate=\"collapsed\" desc=\" Look and feel setting code (optional) \">         /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.          * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html           */         try {             for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {                 if (\"Nimbus\".equals(info.getName())) {                     javax.swing.UIManager.setLookAndFeel(info.getClassName());                     break;                 }             }         } catch (ClassNotFoundException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         } catch (InstantiationException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         } catch (IllegalAccessException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         } catch (javax.swing.UnsupportedLookAndFeelException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         }         //</editor-fold>          /* Create and display the form */         java.awt.EventQueue.invokeLater(new Runnable() {             public void run() {                 new VentanaPrincipal().setVisible(true);             }         });     }      } ");
        Output.add(textArea2, java.awt.BorderLayout.CENTER);

        jTabbedPane5.addTab("Output - Practicas2SMM (run)", Output);

        jSplitPane1.setBottomComponent(jTabbedPane5);

        Properties.setLayout(new java.awt.BorderLayout());

        jList1.setModel(new javax.swing.AbstractListModel<String>() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public String getElementAt(int i) { return strings[i]; }
        });
        jScrollPane1.setViewportView(jList1);

        Properties.add(jScrollPane1, java.awt.BorderLayout.CENTER);

        jTabbedPane4.addTab("Properties", Properties);

        Palette.setLayout(new java.awt.BorderLayout());

        jToolBar1.setRollover(true);
        Palette.add(jToolBar1, java.awt.BorderLayout.CENTER);

        jTabbedPane4.addTab("Palette", Palette);

        jSplitPane2.setRightComponent(jTabbedPane4);

        Archivos.setLayout(new java.awt.BorderLayout());

        textArea1.setText("/*  * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license  * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template  */ package practica2smm;  /**  *  * @author joset  */ public class Practica2SMM {      public static void main(String args[]) {         /* Set the Nimbus look and feel */         //<editor-fold defaultstate=\"collapsed\" desc=\" Look and feel setting code (optional) \">         /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.          * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html           */         try {             for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {                 if (\"Nimbus\".equals(info.getName())) {                     javax.swing.UIManager.setLookAndFeel(info.getClassName());                     break;                 }             }         } catch (ClassNotFoundException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         } catch (InstantiationException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         } catch (IllegalAccessException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         } catch (javax.swing.UnsupportedLookAndFeelException ex) {             java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);         }         //</editor-fold>          /* Create and display the form */         java.awt.EventQueue.invokeLater(new Runnable() {             public void run() {                 new VentanaPrincipal().setVisible(true);             }         });     }      } ");
        Archivos.add(textArea1, java.awt.BorderLayout.CENTER);

        jTabbedPane3.addTab("Practicas2SMM.java", Archivos);

        jSplitPane2.setLeftComponent(jTabbedPane3);

        jSplitPane1.setLeftComponent(jSplitPane2);

        jPanel3.add(jSplitPane1, java.awt.BorderLayout.CENTER);

        jSplitPane5.setRightComponent(jPanel3);

        getContentPane().add(jSplitPane5, java.awt.BorderLayout.CENTER);

        jMenu1.setText("File");
        jMenuBar1.add(jMenu1);

        jMenu2.setText("Edit");
        jMenuBar1.add(jMenu2);

        jMenu3.setText("View");
        jMenuBar1.add(jMenu3);

        jMenu4.setText("Navigate");
        jMenuBar1.add(jMenu4);

        jMenu5.setText("Source");
        jMenuBar1.add(jMenu5);

        jMenu6.setText("Refractor");
        jMenuBar1.add(jMenu6);

        jMenu7.setText("Run");
        jMenuBar1.add(jMenu7);

        jMenu8.setText("Debug");
        jMenuBar1.add(jMenu8);

        jMenu9.setText("Profile");
        jMenuBar1.add(jMenu9);

        jMenu10.setText("Team");
        jMenuBar1.add(jMenu10);

        jMenu11.setText("Tools");
        jMenuBar1.add(jMenu11);

        jMenu12.setText("Windows");
        jMenuBar1.add(jMenu12);

        jMenu13.setText("Help");
        jMenuBar1.add(jMenu13);

        setJMenuBar(jMenuBar1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel Archivos;
    private javax.swing.JPanel Files1;
    private javax.swing.JPanel Navigator;
    private javax.swing.JPanel Output;
    private javax.swing.JPanel Palette;
    private javax.swing.JTree Practica2SMM;
    private javax.swing.JTree Practica2SMM2;
    private javax.swing.JTree Practica2SMM3;
    private javax.swing.JPanel Projects1;
    private javax.swing.JPanel Properties;
    private javax.swing.JPanel Services1;
    private javax.swing.JDesktopPane jDesktopPane2;
    private javax.swing.JInternalFrame jInternalFrame2;
    private javax.swing.JList<String> jList1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu10;
    private javax.swing.JMenu jMenu11;
    private javax.swing.JMenu jMenu12;
    private javax.swing.JMenu jMenu13;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenu jMenu4;
    private javax.swing.JMenu jMenu5;
    private javax.swing.JMenu jMenu6;
    private javax.swing.JMenu jMenu7;
    private javax.swing.JMenu jMenu8;
    private javax.swing.JMenu jMenu9;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JSplitPane jSplitPane1;
    private javax.swing.JSplitPane jSplitPane2;
    private javax.swing.JSplitPane jSplitPane3;
    private javax.swing.JSplitPane jSplitPane5;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTabbedPane jTabbedPane2;
    private javax.swing.JTabbedPane jTabbedPane3;
    private javax.swing.JTabbedPane jTabbedPane4;
    private javax.swing.JTabbedPane jTabbedPane5;
    private javax.swing.JToolBar jToolBar1;
    private java.awt.TextArea textArea1;
    private java.awt.TextArea textArea2;
    // End of variables declaration//GEN-END:variables
}
