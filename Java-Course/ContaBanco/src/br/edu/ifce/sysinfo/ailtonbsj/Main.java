package br.edu.ifce.sysinfo.ailtonbsj;

class Main {
	public static void detalhesDaConta(ContaBanco conta) {
		System.out.println("-------------");
		System.out.println("Nome: " + conta.getDono());
		System.out.println("Status: " + conta.isEnabled());
		System.out.println("Tipo: " + conta.getTipo());
		System.out.println("Saldo: " + conta.getSaldo());
		System.out.println("Limite: " + conta.getLimite());
	}
  public static void main(String[] args) {
    ContaBanco joao = new ContaBanco(123456789, "João Paulo Silva");
		detalhesDaConta(joao);
		
		ContaBanco josue = new ContaBanco(123456788, "josue");
		josue.setDono("Josue Felipe");
		josue.setTipo(TipoDeConta.POUPANCA);
		josue.depositar(114.35);
		josue.setLimite(1000);
		josue.sacar(50);
		josue.pagarMensal(10, "Apostas do Bet");
		detalhesDaConta(josue);

		ContaBanco maria = new ContaBanco(123456788, "maria");
		maria.abrirConta();
		maria.setDono("Maria Clara Lima");
		maria.setTipo(TipoDeConta.POUPANCA);
		maria.depositar(100);
		maria.depositar(120.45);
		maria.setLimite(200);
		maria.sacar(150);
		maria.pagarMensal(20, "Conta de Luz");
		detalhesDaConta(maria);

		maria.sacar(200);
		detalhesDaConta(maria);

		maria.sacar(100);
		detalhesDaConta(maria);

  }
}