// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int		main( void ) {

	
	typedef std::vector<Account::t>							  accounts_t;				// Accounts_t is a vector of Account objects
	typedef std::vector<int>								  ints_t;					// ints_t is a vector of integers
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;				// A pair of iterators: one for accounts, one for ints

	
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };	// Initial amounts
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );				// Number of elements in the amounts array
	accounts_t				accounts( amounts, amounts + amounts_size );				// Initialize a vector of Account objects using the amounts array

	accounts_t::iterator	acc_begin	= accounts.begin();		// Iterator pointing to the beginning of the accounts vector
	
	accounts_t::iterator	acc_end		= accounts.end();		// Iterator pointing to the end
	
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };	// Array of deposit amounts for each account
	size_t const		d_size( sizeof(d) / sizeof(int) );					// Calculate the number of elements in the deposits array
	ints_t				deposits( d, d + d_size );							// Initialize a vector of deposit amounts
	ints_t::iterator	dep_begin	= deposits.begin();						// Iterator pointing to the beginning of the deposits vector
	ints_t::iterator	dep_end		= deposits.end();						// Iterator pointing to the end of the deposits vector

	
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };	// Same for withdrawals
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	for (accounts_t::iterator it = acc_begin; it != acc_end; ++it)
		it->displayStatus();

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {
		(*(it.first)).makeDeposit( *(it.second) );
	}

	// Display overall information about all accounts after deposits
	Account::displayAccountsInfos();
	// Display the status of each account after deposits
	for (accounts_t::iterator it = acc_begin; it != acc_end; ++it)
		it->displayStatus();

	// Loop over accounts and withdrawals simultaneously using a pair of iterators
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		// Attempt to withdraw the specified amount from the current account
		// The makeWithdrawal function will handle if the withdrawal is possible or not
		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// Display overall information about all accounts after withdrawals
	Account::displayAccountsInfos();
	// Display the status of each account after withdrawals
	for (accounts_t::iterator it = acc_begin; it != acc_end; ++it)
		it->displayStatus();

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
