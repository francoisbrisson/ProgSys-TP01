#ifndef ARBREBINAIRE_H__
#define ARBREBINAIRE_H__


template <class T>
class ArbreBinaire
{
public:
	ArbreBinaire();
	~ArbreBinaire();

	void Afficher();
	void Ajouter(const T& valeur);
	void Enlever(const T& valeur);
	void Vider();
	bool Contient(const T& valeur);
	int Nombre() const;

	const T& Minimum() const;
	const T& Maximum() const;
	void AfficherCroissant() const;
	void AfficherDecroissant() const;

private:
	struct Noeud
	{
		T valeur;
		Noeud* gauche;
		Noeud* droite;

		Noeud(const T& valeur, Noeud* gauche, Noeud* droite) : valeur(valeur), gauche(gauche), droite(droite) {}
	};
	Noeud* m_debut = 0;
	int m_count = 0;
};

template <class T>
ArbreBinaire<T>::ArbreBinaire()
{
}

template <class T>
ArbreBinaire<T>::~ArbreBinaire()
{
	Vider();
}

template <class T>
void ArbreBinaire<T>::Afficher()
{
}

template <class T>
void ArbreBinaire<T>::Ajouter(const T& valeur)
{
	Noeud* n = m_debut;
	Noeud* precedent = nullptr;

	if (m_count == 0)
		m_debut = new Noeud*(valeur);
	/*if (n->valeur == valeur)
		return;*/

	do
	{
		if (valeur < n->valeur)
		{
			precedent = n;
			n = n->gauche;
			if (n->valeur < n->droite->valeur && !n->gauche)
				n->gauche == new Noeud*(valeur);
		}
		else if (valeur > n->valeur)
		{
			precedent = n;
			n = n->droite;
		}
		else
		{
			
			++m_count;
		}
	} 
	while (n->valeur != valeur);

}

template <class T>
void ArbreBinaire<T>::Enlever(const T& valeur)
{
}

template <class T>
void ArbreBinaire<T>::Vider()
{
}

template <class T>
bool ArbreBinaire<T>::Contient(const T& valeur)
{
}

template <class T>
int ArbreBinaire<T>::Nombre() const
{
	return m_count;
}

template <class T>
const T& ArbreBinaire<T>::Minimum() const
{
}

template <class T>
const T& ArbreBinaire<T>::Maximum() const
{
}

template <class T>
void ArbreBinaire<T>::AfficherCroissant() const
{
}

template <class T>
void ArbreBinaire<T>::AfficherDecroissant() const
{
}

#endif
