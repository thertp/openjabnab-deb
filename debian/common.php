<?php
define('ROOT_SITE', realpath(dirname(__FILE__)."/../")."/");
if (file_exists("/etc/openjabnab/common.php")) {
	include("/etc/openjabnab/common.php");
} else {
	define('ROOT_WWW_ADMIN', 'http://localhost/ojn_admin/');
	define('ROOT_WWW_API', 'http://localhost/ojn_api/');
	define('ADMIN_EMAIL', 'openjabnab@localhost');
}

session_start(['openJabNab']);
require_once(ROOT_SITE.'class/api.class.php');
require_once(ROOT_SITE.'class/template.class.php');
$ojnAPI = new ojnApi();
$ojnTemplate = new ojnTemplate($ojnAPI);
$Infos = array('token' => '','login'=>'guest','usename'=>'Guest','isAdmin'=>false,'isValid'=>true);
if(isset($_SESSION['token']) && !strpos($_SERVER['REQUEST_URI'],"logout")) {
    if(isset($_SESSION['token']) && isset($_SESSION['login'])) {
        $Infos = $ojnAPI->getApiMapped('accounts/infos?user='.$_SESSION['login'].'&'.$ojnAPI->getToken());
		/* Fix to convert 'true' to true, etc */
		if(isset($Infos['isAdmin']))
			$Infos['isAdmin'] = $Infos['isAdmin'] != 'false' ? true : false;
		if(isset($Infos['isValid']))
			$Infos['isValid'] = $Infos['isValid'] != 'false' ? true : false;
	}
	if(!$Infos['isValid'])
		header('Location: index.php?logout');
}
$translations = array();
if(isset($Infos['language']))
{
	if(file_exists(ROOT_SITE.'class/translations.'.$Infos['language'].'.php'))
		require_once(ROOT_SITE.'class/translations.'.$Infos['language'].'.php');
}
$ojnTemplate->setUInfos($Infos);
ob_start(array($ojnTemplate,'display'));
?>

