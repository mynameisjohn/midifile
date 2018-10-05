//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Sat Feb 14 21:55:38 PST 2015
// Last Modified: Sat Feb 14 21:55:40 PST 2015
// Filename:      midifile/include/MidiEventList.h
// Website:       http://midifile.sapp.org
// Syntax:        C++11
// vim:           ts=3 expandtab
//
// Description:   A class which stores a MidiEvents for a MidiFile track.
//

#ifndef _MIDIEVENTLIST_H_INCLUDED
#define _MIDIEVENTLIST_H_INCLUDED

#include "MidiEvent.h"
#include <vector>

namespace mifi
{
	class MidiEventList
	{
	public:
		using Iter = std::vector<MidiEvent *>::iterator;
		using IterC = std::vector<MidiEvent *>::const_iterator;

		MidiEventList    ( void );

		~MidiEventList    ();

		MidiEventList     ( const MidiEventList& other );
		MidiEventList     ( MidiEventList&& other );

		MidiEvent&  operator[]       ( int index );
		const MidiEvent&  operator[] ( int index ) const;
		MidiEvent&  back             ( void );
		MidiEvent&  last             ( void );
		MidiEvent&  getEvent         ( int index );
		void        clear            ( void );
		void        reserve          ( int rsize );
		int         getSize          ( void ) const;
		int         size             ( void ) const;
		int         linkNotePairs    ( void );
		int         linkEventPairs   ( void );
		void        clearLinks       ( void );
		MidiEvent** data             ( void );

		int         push             ( MidiEvent& event );
		int         push_back        ( MidiEvent& event );
		int         append           ( MidiEvent& event );

        bool        removeEventAt    (int anIndex);
        int         removeEventsAfterTick (int tick);

		// careful when using these, intended for internal use in MidiFile class:
		void        detach              ( void );
		int         push_back_no_copy   ( MidiEvent* event );

		MidiEventList& operator=( const MidiEventList& other );
        MidiEventList& operator=(MidiEventList&& other);

		inline Iter begin() { return list.begin(); }
		inline Iter end() { return list.end(); }
		inline IterC begin() const { return list.cbegin(); }
		inline IterC end() const { return list.cend(); }
		inline bool empty() const { return list.empty(); }

	private:
		std::vector<MidiEvent*>     list;

	};
}

#endif /* _MIDIEVENTLIST_H_INCLUDED */



