# Base Project
Base project with git LFS configured

## Develop
1. Install [Git-LFS](https://git-lfs.github.com/)
    
    ```choco install git-lfs --yes```
	
2. Clone this repo. (You will need a valid IAM account with Git Security Credentials setup


	a. Login with your IAM credentials (username + password) and root account ID

	b. Top-right, go to "My Security Credentials"

	c. Select the "AWS COdeCommit Credentials" tab
	d. Select Generate HTTPS Git Credentials (these will be used to authenticate against CodeCommit git)

3. Initialize git-lfs in the folder

    ```git lfs install```

4. Open project's solution via VS 2019

5. Build and launch Editor in "Development" configuration. 

Note: Most C++ changes can be hot-reloaded by clicking the compile icon in-engine instead of restarting the editor via the IDE.
