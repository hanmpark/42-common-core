import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import Button from 'react-bootstrap/Button';
import { AuthenticationSection, FormContainer, LanguageDropdownButton } from './styles/Authentication.styled';
import { checkSignUpRestrictions } from '../../scripts/restrictions';
import FakeCaptcha from './FakeCaptcha';
import ErrorMessage from '../../styles/shared/ErrorMessage.styled';

const SignUp = () => {
	const [formData, setFormData] = useState({
		username: '',
		email: '',
		password: '',
		lang: 'en',
	});
	const [cfPassword, setCfPassword] = useState('');
	const [showPassword, setShowPassword] = useState(false);
	const [showCfPassword, setShowCfPassword] = useState(false);
	const [showFakeCaptcha, setShowFakeCaptcha] = useState(false);
	const [error, setError] = useState('');

	const handleChange = e => {
		const { id, value } = e.target;

		setFormData(prevData => ({
			...prevData,
			[id]: value,
		}));
	};

	const handleSubmit = event => {
		event.preventDefault();
		const errorMessage = checkSignUpRestrictions(formData, cfPassword);
		if (errorMessage) {
			setError(errorMessage);
		} else {
			setShowFakeCaptcha(true);
		}
	};

	return (
		<AuthenticationSection>
			{!showFakeCaptcha ? (
				<FormContainer onSubmit={handleSubmit}>
					<h1>Sign Up</h1>
					<LanguageDropdownButton
						id="lang"
						value={formData.lang}
						onChange={handleChange}
						autoComplete='off'
					>
						<option value="en">🇬🇧 English</option>
						<option value="es">🇪🇸 Español</option>
						<option value="fr">🇫🇷 Français</option>
					</LanguageDropdownButton>
					<FormContainer.Group className="mb-3">
						<FormContainer.Control
							id="username"
							type="username"
							placeholder=" "
							value={formData.username}
							onChange={handleChange}
							isInvalid={error && error.includes('Username')}
							autoComplete='username'
						/>
						<span>USERNAME</span>
					</FormContainer.Group>
					<FormContainer.Group className="mb-3">
						<FormContainer.Control
							id="email"
							type="email"
							placeholder=" "
							value={formData.email}
							onChange={handleChange}
							isInvalid={error && error.includes('Email')}
							autoComplete='email'
						/>
						<span>E-MAIL</span>
					</FormContainer.Group>
					<FormContainer.Group className="mb-3">
						<FormContainer.Control
							id="password"
							type={showPassword ? 'text' : 'password'}
							placeholder=" "
							value={formData.password}
							onChange={handleChange}
							isInvalid={error && error.includes('Password')}
							autoComplete='new-password'
						/>
						<span>PASSWORD</span>
						{showPassword ? (
							<i className="bi bi-eye-fill" onClick={() => setShowPassword(!showPassword)}/>
						) : (
							<i className="bi bi-eye" onClick={() => setShowPassword(!showPassword)}/>
						)}
					</FormContainer.Group>
					<FormContainer.Group className="mb-3">
						<FormContainer.Control
							id="cfpassword"
							type={showCfPassword ? 'text' : 'password'}
							placeholder=" "
							value={cfPassword}
							onChange={(e) => setCfPassword(e.target.value)}
							isInvalid={error && error.includes('Passwords')}
							autoComplete='new-password'
						/>
						<span>CONFIRM</span>
						{showCfPassword ? (
							<i className="bi bi-eye-fill" onClick={() => setShowCfPassword(!showCfPassword)}/>
						) : (
							<i className="bi bi-eye" onClick={() => setShowCfPassword(!showCfPassword)}/>
						)}
					</FormContainer.Group>
					<p>Already Signed Up ? <Link to="/signin">Sign In</Link></p>
					{error && <ErrorMessage>{error}</ErrorMessage>}
					<Button variant='light' type='submit'>Submit</Button>
				</FormContainer>
			) : <FakeCaptcha formData={formData}/>}
		</AuthenticationSection>
	);
};

export default SignUp;
