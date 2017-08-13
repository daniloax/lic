package model;

public interface Estrutura {
	
	/* controi estrutura */
	public void construir();
	
	/* insere dado na estrutura */
	public void inserir(Object dado);
	
	/* procura dado na estrutura */
	public boolean procurar(Object dado);
	
	/* retorna raiz da estrutura */
	public Object raiz();
	
	/* remove raiz da estrutura e retorna o objeto removido */
	public Object remover();
	
	/* remove dado da estutura */
	public void remover(Object dado);
	
	/* exibe elementos da estrutura */
	public void ler();

}
