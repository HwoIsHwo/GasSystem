function varargout = get(~, propname)
switch lower(propname)
    case 'header'
        if nargout > 1
            error('Too many output arguments');
        end
        h = mexxfile('get', 'header');
        h.addon   = native2unicode(h.addon);
        h.comment = native2unicode(h.comment);
        pt = h.shottime_sec + h.shottime_usec*1e-6;
        h.date = datetime(pt, 'ConvertFrom', 'posixtime', 'TimeZone', 'Etc/GMT-6');
        if ~isempty(h.addon)
            xmlDocument = javax.xml.parsers.DocumentBuilderFactory.newInstance().newDocumentBuilder.parse(java.io.StringBufferInputStream(h.addon));
            nodeList = xmlDocument.getElementsByTagName('name');
            numberOfNodes = nodeList.getLength();
            h.chnames = cell(1,numberOfNodes);
            for i = 1:numberOfNodes
                firstNode = nodeList.item(i-1);
                h.chnames{i} = char(firstNode.getTextContent);
            end
            h.chnames = matlab.lang.makeValidName(h.chnames);
        end
        
        varargout{1} = h;
        
    case 'dataheader'
        if nargout > 1
            error('Too many output arguments');
        end
        varargout{1} = mexxfile('get', 'dataheader');
        varargout{1}.delta = 1/round(1/varargout{1}.delta);
    case 'data'
        if nargout > 2
            error('Too many output arguments');
        end
        varargout{1} = double(mexxfile('get', 'data')).';
        if nargout == 2
            dh = mexxfile('get', 'dataheader');
            dh.delta = 1/round(1/dh.delta);
            varargout{2} = linspace(dh.starttime, dh.starttime + (dh.samplenum-1)*dh.delta, dh.samplenum).';
            
        end
    otherwise
        error(['Uknown property name', propname, '.']);
end
       
       