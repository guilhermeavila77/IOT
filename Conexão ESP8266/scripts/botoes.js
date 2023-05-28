const ligar = document.getElementById('ligar');

ligar.addEventListener('click', () => {
    console.log('botão clicado')
    window.location.href = '/ligar'; // Redireciona para '/nova-rota'
});