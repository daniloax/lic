
  import javax.swing.JFrame;
  
  public class DrawCenteredCircle {
  
      public static void main(String[] args) {
      
         int x, y, r;
         
         x = 3;
         y = 5;
         r = 2;
         
         JFrame frame = new JFrame();
         Painel painel = new Painel();
         
         frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
         frame.add(painel);
         frame.setSize(500,500);
         frame.setVisible(true);
         
         
         System.out.printf("%.15f\n", Math.PI);
         
      }
   
   }
