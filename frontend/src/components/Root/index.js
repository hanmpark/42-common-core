import React, { useCallback, useEffect, useState } from 'react';
import { Outlet, useLocation } from 'react-router-dom';
import NavBar from '../Navigation/Navigation';
import Chat from '../Chat/Chat';
import Footer from '../Footer/Footer';
import { useAuth } from '../../context/AuthContext';
import RelationProvider from '../../context/RelationContext';
import ConnectedNavBar from '../Navigation/ConnectedNavigation';
import TournamentProvider from '../../context/TournamentContext';
import API from '../../api/api';
import { useNotification } from '../../context/NotificationContext';

const Root = () => {
	const location = useLocation();
	const { user, isLoggedIn, setUser } = useAuth();
	const { addNotification } = useNotification();
	const [showPersistentUI, setShowPersistentUI] = useState(true);
	const [hasInteracted, setHasInteracted] = useState(false);
	const [audio] = useState(new Audio('/sounds/pong-theme.mp3'));
	const [audioGame] = useState(new Audio('/sounds/pong-ingame.mp3'));

	const activateMusic = useCallback(() => {
		if (!hasInteracted) {
			setHasInteracted(true);
		}
	}, [hasInteracted]);

	useEffect(() => {
		setShowPersistentUI(!location.pathname.includes('/game'));

		audio.loop = true;

		document.body.addEventListener('click', activateMusic);

		return () => {
			document.body.removeEventListener('click', activateMusic);
		}
	}, [location, audio, activateMusic]);

	useEffect(() => {
		if (!user?.tournamentID) return;

		const leaveTournament = async () => {
			try {
				await API.delete(`/tournaments/@me`);
				setUser(prev => ({
					...prev,
					tournamentID: null,
				}))
				addNotification('info', "Due to you leaving, you've been removed from the tournament");
			} catch (error) {
				addNotification('error', error?.response?.data?.error || 'Error leaving tournament');
			}
		};
		if (!location.pathname.includes(`/tournaments/${user.tournamentID}`)) {
			leaveTournament();
			console.log('index.js: leaving tournament');
		}
	}, [location, user?.tournamentID, addNotification, setUser]);

	useEffect(() => {
		if (hasInteracted && showPersistentUI && isLoggedIn) {
			audioGame.pause();
			audioGame.currentTime = 0;
			audio.volume = 0.2;
			audio.play();
		} else if (hasInteracted && !showPersistentUI && isLoggedIn) {
			audio.pause();
			audio.currentTime = 0;
			audioGame.volume = 0.2;
			audioGame.play();
		} else if (showPersistentUI && !isLoggedIn) {
			audio.pause();
			audio.currentTime = 0;
		}
	}, [hasInteracted, showPersistentUI, audio, isLoggedIn, audioGame]);

	return (
		<>
			{isLoggedIn ? (
				<TournamentProvider>
					<RelationProvider>
						{showPersistentUI && <ConnectedNavBar/>}
						<main>
							<Chat/>
							<Outlet/>
						</main>
						{showPersistentUI && <Footer/>}
					</RelationProvider>
				</TournamentProvider>
			) : (
				<>
					{showPersistentUI && <NavBar/>}
					<main>
						<Outlet/>
					</main>
					{showPersistentUI && <Footer/>}
				</>
			)}
		</>
	);
};

export default Root;
