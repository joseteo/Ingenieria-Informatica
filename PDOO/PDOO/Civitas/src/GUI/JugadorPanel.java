/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package GUI;
import civitas.Jugador;
/**
 *
 * @author teo
 */
public class JugadorPanel extends javax.swing.JPanel {
    Jugador jugador;
    /**
     * Creates new form JugadorPanel
     */
    public JugadorPanel() {
        initComponents();
        repaint();
        revalidate();
    }
    
    public void setJugador(Jugador j){
        jugador=j;
        this.nombrev.setText(jugador.getNombre());
        String s=String.valueOf(jugador.getSaldo());
        this.saldov.setText(s);
        repaint(); 
        revalidate();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        nombrev = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        saldov = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        especuladorv = new javax.swing.JTextField();
        propiedadesPanel = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();

        jLabel1.setText("Nombre:");

        nombrev.setEditable(false);
        nombrev.setBackground(new java.awt.Color(238, 238, 238));
        nombrev.setText("nombreV");
        nombrev.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nombrevActionPerformed(evt);
            }
        });

        jLabel2.setText("Saldo:");

        saldov.setEditable(false);
        saldov.setBackground(new java.awt.Color(238, 238, 238));
        saldov.setText("saldoV");
        saldov.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saldovActionPerformed(evt);
            }
        });

        jLabel3.setText("Especulador");

        especuladorv.setEditable(false);
        especuladorv.setBackground(new java.awt.Color(238, 238, 238));
        especuladorv.setText("especuladorV");

        propiedadesPanel.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));

        jLabel4.setText("Propiedades");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(101, 101, 101)
                        .addComponent(jLabel1)
                        .addGap(5, 5, 5)
                        .addComponent(nombrev, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(117, 117, 117)
                        .addComponent(jLabel2)
                        .addGap(5, 5, 5)
                        .addComponent(saldov, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(70, 70, 70)
                        .addComponent(propiedadesPanel, javax.swing.GroupLayout.PREFERRED_SIZE, 484, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(126, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(80, 80, 80)
                .addComponent(jLabel3)
                .addGap(5, 5, 5)
                .addComponent(especuladorv, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel4)
                .addGap(187, 187, 187))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(10, 10, 10)
                        .addComponent(jLabel1))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(5, 5, 5)
                        .addComponent(nombrev, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(5, 5, 5)
                        .addComponent(jLabel2))
                    .addComponent(saldov, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(5, 5, 5)
                                .addComponent(jLabel3))
                            .addComponent(especuladorv, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addComponent(propiedadesPanel, javax.swing.GroupLayout.PREFERRED_SIZE, 246, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jLabel4))
                .addContainerGap(21, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void nombrevActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nombrevActionPerformed
        nombrev.setText(jugador.getNombre());
        repaint();
        revalidate();
    }//GEN-LAST:event_nombrevActionPerformed

    private void saldovActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saldovActionPerformed
       String s=String.valueOf(jugador.getSaldo());
       saldov.setText(s);
       repaint();
       revalidate();
    }//GEN-LAST:event_saldovActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField especuladorv;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JTextField nombrev;
    private javax.swing.JPanel propiedadesPanel;
    private javax.swing.JTextField saldov;
    // End of variables declaration//GEN-END:variables
}
