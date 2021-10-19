import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
public class EvolDisplay extends JFrame {
    private JTextArea jf;
    private JTextField set;
    private JPanel jp;
    private JPanel rightbar;
    private JTextArea gen;
    private JTextArea high;
    private JTextArea avg;
    private BorderLayout b;
    private JScrollPane jscp;
    private DotHandler dh;
    private int width = 800;
    private int height = 500;
    private int bordergap = 20;
    private Graphics g;
        
    public EvolDisplay(){
        super("Partition Problem Evolutionary Alorithm");
        b = new BorderLayout();
       setLayout(b);
       pack();
       jf = new JTextArea();
       set = new JTextField();
       rightbar = new JPanel();
       jscp = new JScrollPane();
       jscp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
       gen = new JTextArea();
       high = new JTextArea();
       avg = new JTextArea();
       dh = new DotHandler();
       jf.setEditable(false);
       jf.setBackground(Color.WHITE);
       jf.setForeground(Color.BLACK);
       gen.setEditable(false);
       high.setEditable(false);
       avg.setEditable(false);
       add(jf, b.NORTH);
       add(rightbar, b.SOUTH);
       add(jscp);
       add(dh,b.CENTER);
       rightbar.setLayout(new BoxLayout(rightbar, BoxLayout.Y_AXIS));
       rightbar.add(gen);
       rightbar.add(high);
       rightbar.add(avg);
       gen.setText("Generations: ");
       high.setText("Highest Fitness: ");
       avg.setText("Average Fitness: ");
       setSize(1000, 600);
       setVisible(true);
       setLocationRelativeTo(null);
       addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent event) {
          System.exit(0);
        }
      });
    }
  public String input(String Prompt){
    String ans = JOptionPane.showInputDialog(Prompt);
    return ans;
  }    
  
  public void GetNumset(NumberSet s){
    set.setText(s.toString());
  }

  public void endstats( int High, int AVG, Chromosome hghest, int i, int generations){
    int temp4 = bordergap+ i;
    int temp5 = height -AVG + bordergap;
    int temp6 = AVG;
    Dot temp0 = new Dot(temp4, temp5,temp6);
    dh.insertdot(temp0);
    String temp = "Generation: \n" + i;
    gen.setText(temp);
    String temp2 = "Highest Fitness: \n" + High;
    high.setText(temp2);
    String temp3 = "Average Fitness: \n" + AVG;
    avg.setText(temp3);
    jf.setText("Highest fit chromosome set: " + hghest.toString());
    dh.repaint();
    }
}
