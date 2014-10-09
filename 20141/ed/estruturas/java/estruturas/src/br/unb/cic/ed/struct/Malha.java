package br.unb.cic.ed.struct;

import java.util.Random;

public class Malha {
	
	public Malha() {

	}
	
	public Elemento construir(Elemento no) {
		
		Elemento no_a, no_b, no_c, no_d;

		Random randomNumbers;
		int valorCaracter;
		
		no_b = new Elemento();
		no_d = new Elemento();
		randomNumbers = new Random();
		
		for (int i = 0; i < 10; i++) {
			
			valorCaracter = 65 + randomNumbers.nextInt(15);
			
			if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {
				
				no_a = new Elemento((char) valorCaracter, null);
				
				if (no == null)
					no = no_a;
				
				else
					no_b.setProx(no_a);
				
				no_b = no_a;
				
				for (int j = 0; j < 10; j++) {
					
					valorCaracter = 65 + randomNumbers.nextInt(15);
					
					if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {
						
						no_c = new Elemento((char) valorCaracter, null);
						
						if (no_a.getAnt() == null)
							no_a.setAnt(no_c);
						
						else
							no_d.setProx(no_c);
						
						no_d = no_c;
					}
					
				}
				
			}
				
		}
		
		return no;
		
	}
	
	public void ler(Elemento no) {
		
		Elemento no_a, no_b;
		
		if (no == null)
			System.out.printf("lista vazia");
		
		else {
			
			no_a = no;
			
			while (no_a != null) {
				
				System.out.printf("\n %c", (char) no_a.getDado());
				no_b = no_a.getAnt();
				
				while (no_b != null) {
					
					System.out.printf("%5c", (char) no_b.getDado());
					no_b = no_b.getProx();
					
				}
				
				no_a = no_a.getProx();
				
			}
			
		}
		
		System.out.println();
		
	}

}
