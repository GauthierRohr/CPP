// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );			// pour TOUS les comptes au total
	static int	getNbDeposits( void );			// idem
	static int	getNbWithdrawals( void );		// idem
	static void	displayAccountsInfos( void );

	
	Account( int initial_deposit ); 			// Constructeur: crée compte avec dépot initial
	~Account( void );							// Destructeur: clean Account quand obj Account détruit

	void	makeDeposit( int deposit );			// Dépot : update total du compte + compteur de déposits
	bool	makeWithdrawal( int withdrawal );	// Un compte veut withdraw : return true si ok,  update total du compte + compteur de withdraw
	int		checkAmount( void ) const;			// Retourne le total de thunes actuel d'un compte
	void	displayStatus( void ) const;		// Affiche le statut actuel d'un compte (amount, deposits, withdrawals)

private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;          			// Current balance of this account
	int				_nbDeposits;      			// Pour ce compte
	int				_nbWithdrawals;   			// idem

	// Private default constructor to prevent creating accounts without initial deposit
	Account( void );
};



//
// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
